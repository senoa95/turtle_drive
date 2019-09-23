function [allData, scenario, sensors] = EGO_Follow_Vehicle_Left_Turn()
%EGO_Follow_Vehicle_Left_Turn - Returns sensor detections
%    allData = EGO_Follow_Vehicle_Left_Turn returns sensor detections in a structure
%    with time for an internally defined scenario and sensor suite.
%
%    [allData, scenario, sensors] = EGO_Follow_Vehicle_Left_Turn optionally returns
%    the drivingScenario and detection generator objects.

% Generated by MATLAB(R) 9.5 and Automated Driving System Toolbox 1.3.
% Generated on: 07-Dec-2018 22:14:29

% Create the drivingScenario object and ego car
[scenario, egoCar] = createDrivingScenario;

% Create all the sensors
[sensors, numSensors] = createSensors(scenario);

allData = struct('Time', {}, 'ActorPoses', {}, 'ObjectDetections', {}, 'LaneDetections', {});
running = true;
while running
    
    % Generate the target poses of all actors relative to the ego car
    poses = targetPoses(egoCar);
    % Generate the boundaries of all lanes relative to the ego car for 100m
%     lanes = laneBoundaries(egoCar, 'XDistance', 100);
    time  = scenario.SimulationTime;
    
    objectDetections = {};
    laneDetections   = [];
    isValidTime      = false(1, numSensors);
    isValidLaneTime  = false(1, numSensors);
    
    % Generate detections for each sensor
    for sensorIndex = 1:numSensors
        lanes = laneBoundaries(egoCar, 'XDistance', linspace(0, sensors{sensorIndex}.MaxRange, 100));
        type = getDetectorOutput(sensors{sensorIndex});
        if strcmp(type, 'Objects only')
            [objectDets, numObjects, isValidTime(sensorIndex)] = sensors{sensorIndex}(poses, time);
            objectDetections = [objectDetections; objectDets(1:numObjects)]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes only')
            [laneDets, ~, isValidTime(sensorIndex)] = sensors{sensorIndex}(lanes, time);
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes and objects')
            [objectDets, numObjects, isValidTime(sensorIndex), laneDets, ~, isValidLaneTime(sensorIndex)] = sensors{sensorIndex}(poses, lanes, time);
            objectDetections = [objectDetections; objectDets(1:numObjects)]; %#ok<AGROW>
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes with occlusion')
            [laneDets, ~, isValidLaneTime(sensorIndex)] = sensors{sensorIndex}(poses, lanes, time);
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        end
    end
    
    % Aggregate all detections into a structure for later use
    if any(isValidTime) || any(isValidLaneTime)
        allData(end + 1) = struct( ...
            'Time',       scenario.SimulationTime, ...
            'ActorPoses', actorPoses(scenario), ...
            'ObjectDetections', {objectDetections}, ...
            'LaneDetections',   {laneDetections}); %#ok<AGROW>
    end
    
    % Advance the scenario one time step and exit the loop if the scenario is complete
    running = advance(scenario);
end

% Restart the driving scenario to return the actors to their initial positions.
restart(scenario);

% Release all the sensor objects so they can be used again.
for sensorIndex = 1:numSensors
    release(sensors{sensorIndex});
end

%%%%%%%%%%%%%%%%%%%%
% Helper functions %
%%%%%%%%%%%%%%%%%%%%

% Units used in createSensors and createDrivingScenario
% Distance/Position - meters
% Speed             - meters/second
% Angles            - degrees
% RCS Pattern       - dBsm

function [sensors, numSensors] = createSensors(scenario)
% createSensors Returns all sensor objects to generate detections

% Assign into each sensor the physical and radar profiles for all actors
profiles = actorProfiles(scenario);
sensors{1} = visionDetectionGenerator('SensorIndex', 1, ...
    'SensorLocation', [5.4 0], ...
    'Height', 2.55, ...
    'Pitch', 0.514, ...
    'DetectionProbability', 0.95, ...
    'MaxSpeed', 83, ...
    'DetectorOutput', 'Lanes with occlusion', ...
    'Intrinsics', cameraIntrinsics([800 800],[320 240],[960 1280]), ...
    'ActorProfiles', profiles);
sensors{2} = radarDetectionGenerator('SensorIndex', 2, ...
    'SensorLocation', [7.2 0], ...
    'MaxRange', 100, ...
    'ActorProfiles', profiles);
numSensors = 2;

function [scenario, egoCar] = createDrivingScenario
% createDrivingScenario Returns the drivingScenario defined in the Designer

% Construct a drivingScenario object.
scenario = drivingScenario;

% Add all road segments
roadCenters = [0 0 0;
    65.5 11.3 0;
    100 100 0];
laneSpecification = lanespec(2);
road(scenario, roadCenters, 'Lanes', laneSpecification);

% Add the ego car
egoCar = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [0 -2 0]);
waypoints = [0 -2 0;
    28.1 -1.77 0.01;
    37.1 -1.1 0;
    47.2 1 0;
    63.9 8.4 0;
    74.4 16.3 0;
    81.9 25.1 0;
    89.8 38.7 0;
    94.1 51.3 0;
    98.1 67 0;
    100 81 0];
speed = 20;
trajectory(egoCar, waypoints, speed);

% Add the non-ego actors
truck1 = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [28.1 -1.77 0]);
waypoints = [28.1 -1.77 0;
    37.1 -1.1 0.01;
    47.202 1.001 0.01;
    63.92 8.42 0.01;
    74.42 16.3 0.01;
    82.01 25.14 0.01;
    89.9 38.8 0;
    94.2 51.7 0;
    98.4 67.3 0;
    100.08 81.17 0.01;
    102.01 99.74 0.01];
speed = 20;
trajectory(truck1, waypoints, speed);

function output = getDetectorOutput(sensor)

if isa(sensor, 'visionDetectionGenerator')
    output = sensor.DetectorOutput;
else
    output = 'Objects only';
end

