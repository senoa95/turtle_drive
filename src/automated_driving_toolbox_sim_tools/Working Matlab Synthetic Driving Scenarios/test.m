function [allData, scenario, sensors] = test()
%EGO_Follow_Vehicle_s_curve - Returns sensor detections
%    allData = EGO_Follow_Vehicle_s_curve returns sensor detections in a structure
%    with time for an internally defined scenario and sensor suite.
%
%    [allData, scenario, sensors] = EGO_Follow_Vehicle_s_curve optionally returns
%    the drivingScenario and detection generator objects.

% Generated by MATLAB(R) 9.5 and Automated Driving System Toolbox 1.3.
% Generated on: 03-Dec-2018 18:08:27

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
    'FieldOfView', [100 5], ...
    'ActorProfiles', profiles);
numSensors = 2;

function [scenario, egoCar] = createDrivingScenario
% createDrivingScenario Returns the drivingScenario defined in the Designer

% Construct a drivingScenario object.
scenario = drivingScenario;

% Add all road segments
roadCenters = [50.5 -49.6 0;
    -12.3 10.5 0;
    13.1 47.5 0;
    45.9 51.8 0;
    122.1 51.4 0;
    153.9 51.7 0;
    200.1 119.8 0;
    149 149.1 0];
laneSpecification = lanespec(2);
road(scenario, roadCenters, 'Lanes', laneSpecification);

% Add the ego car
egoCar = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [50 -47.5 0]);
waypoints = [50 -47.5 0;
    29.88 -38.61 0.01;
    17.6 -32.03 0.01;
    9 -25.6 0;
    0.2 -17 0;
    -5.5 -8.2 0;
    -9.5 2.4 0;
    -10 13.1 0;
    -8 22.8 0;
    -4.11 30.36 0.01;
    1.08 36.57 0.01;
    7.84 42.4 0.01;
    15.62 46.11 0.01;
    29.98 49.17 0.01;
    44.85 50.09 0.01;
    64.77 49.86 0.01;
    85 49.98 0.01;
    106.5 50.1 0;
    129.5 49.3 0;
    148.1 49 0;
    159.24 50.5 0.01;
    175.04 55.83 0.01;
    184.32 61.36 0.01;
    192.02 68.18 0.01;
    197.4 74.52 0.01;
    201.54 81.84 0.01;
    205.04 91.15 0.01;
    206.32 102.54 0.01;
    205.4 109.9 0;
    202.8 118.6 0;
    199.7 124 0;
    195 129.6 0;
    186.7 136.5 0;
    180.8 140.3 0;
    173.2 143.5 0;
    165.9 146.3 0;
    155.5 149.4 0;
    149.55 151.08 0.01];
speed = 20;
trajectory(egoCar, waypoints, speed);

% Add the non-ego actors
truck1 = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [36.5 -41.6 0]);
waypoints = [36.5 -41.6 0;
    19.6 -33.2 0;
    9.97 -26.08 0.01;
    1.08 -17.56 0.01;
    -6.12 -7.45 0.01;
    -9.87 5.09 0.01;
    -9.49 16.88 0.01;
    -7.25 24.57 0.01;
    -2.85 32.18 0.01;
    3.33 39.03 0.01;
    10.27 43.86 0.01;
    18.9 47.16 0.01;
    29.22 49.02 0.01;
    43.65 49.91 0.01;
    53.05 50.22 0.01;
    73.7 50.5 0;
    94.8 50 0;
    116.8 50 0;
    136 48.7 0;
    153.7 49.84 0.01;
    165.89 52.34 0.01;
    178.69 57.79 0.01;
    189.92 65.68 0.01;
    197.4 75.16 0.01;
    202.44 82.72 0.01;
    206.22 96.04 0.01;
    206.29 106.01 0.01;
    203.55 116.84 0.01;
    200.35 123.34 0.01;
    193.76 130.75 0.01;
    185.34 137.52 0.01;
    175.37 142.83 0.01;
    164.47 146.89 0.01;
    149.81 151.21 0.01];
speed = 20;
trajectory(truck1, waypoints, speed);

function output = getDetectorOutput(sensor)

if isa(sensor, 'visionDetectionGenerator')
    output = sensor.DetectorOutput;
else
    output = 'Objects only';
end

