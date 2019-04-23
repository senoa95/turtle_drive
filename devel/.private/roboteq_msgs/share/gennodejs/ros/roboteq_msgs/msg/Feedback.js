// Auto-generated. Do not edit!

// (in-package roboteq_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Feedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.motor_current = null;
      this.motor_power = null;
      this.commanded_velocity = null;
      this.measured_velocity = null;
      this.measured_position = null;
      this.supply_voltage = null;
      this.supply_current = null;
      this.motor_temperature = null;
      this.channel_temperature = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('motor_current')) {
        this.motor_current = initObj.motor_current
      }
      else {
        this.motor_current = 0.0;
      }
      if (initObj.hasOwnProperty('motor_power')) {
        this.motor_power = initObj.motor_power
      }
      else {
        this.motor_power = 0.0;
      }
      if (initObj.hasOwnProperty('commanded_velocity')) {
        this.commanded_velocity = initObj.commanded_velocity
      }
      else {
        this.commanded_velocity = 0.0;
      }
      if (initObj.hasOwnProperty('measured_velocity')) {
        this.measured_velocity = initObj.measured_velocity
      }
      else {
        this.measured_velocity = 0.0;
      }
      if (initObj.hasOwnProperty('measured_position')) {
        this.measured_position = initObj.measured_position
      }
      else {
        this.measured_position = 0.0;
      }
      if (initObj.hasOwnProperty('supply_voltage')) {
        this.supply_voltage = initObj.supply_voltage
      }
      else {
        this.supply_voltage = 0.0;
      }
      if (initObj.hasOwnProperty('supply_current')) {
        this.supply_current = initObj.supply_current
      }
      else {
        this.supply_current = 0.0;
      }
      if (initObj.hasOwnProperty('motor_temperature')) {
        this.motor_temperature = initObj.motor_temperature
      }
      else {
        this.motor_temperature = 0.0;
      }
      if (initObj.hasOwnProperty('channel_temperature')) {
        this.channel_temperature = initObj.channel_temperature
      }
      else {
        this.channel_temperature = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Feedback
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [motor_current]
    bufferOffset = _serializer.float32(obj.motor_current, buffer, bufferOffset);
    // Serialize message field [motor_power]
    bufferOffset = _serializer.float32(obj.motor_power, buffer, bufferOffset);
    // Serialize message field [commanded_velocity]
    bufferOffset = _serializer.float32(obj.commanded_velocity, buffer, bufferOffset);
    // Serialize message field [measured_velocity]
    bufferOffset = _serializer.float32(obj.measured_velocity, buffer, bufferOffset);
    // Serialize message field [measured_position]
    bufferOffset = _serializer.float32(obj.measured_position, buffer, bufferOffset);
    // Serialize message field [supply_voltage]
    bufferOffset = _serializer.float32(obj.supply_voltage, buffer, bufferOffset);
    // Serialize message field [supply_current]
    bufferOffset = _serializer.float32(obj.supply_current, buffer, bufferOffset);
    // Serialize message field [motor_temperature]
    bufferOffset = _serializer.float32(obj.motor_temperature, buffer, bufferOffset);
    // Serialize message field [channel_temperature]
    bufferOffset = _serializer.float32(obj.channel_temperature, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Feedback
    let len;
    let data = new Feedback(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [motor_current]
    data.motor_current = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [motor_power]
    data.motor_power = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [commanded_velocity]
    data.commanded_velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [measured_velocity]
    data.measured_velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [measured_position]
    data.measured_position = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [supply_voltage]
    data.supply_voltage = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [supply_current]
    data.supply_current = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [motor_temperature]
    data.motor_temperature = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [channel_temperature]
    data.channel_temperature = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roboteq_msgs/Feedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2b31653367731d6254182bb2f9dbb81a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # 50Hz feedback message for controls purposes
    Header header
    
    # Current flowing in the motors (A)
    float32 motor_current
    
    # Output stage, as a proportion of full (-1..1)
    float32 motor_power
    
    # Commanded and measured speed of the motors (rad/s)
    # Position is reported in rads, and wraps around +-6M
    float32 commanded_velocity
    float32 measured_velocity
    float32 measured_position
    
    # Electrical power supply to the driver (V, A)
    float32 supply_voltage
    float32 supply_current
    
    # Measured temperatures (C)
    # Motor temp is processed from a thermal sensor connected to analog input 1.
    float32 motor_temperature
    # Channel temp is the temperature of the FETs. This is reported by the controller.
    float32 channel_temperature
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Feedback(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.motor_current !== undefined) {
      resolved.motor_current = msg.motor_current;
    }
    else {
      resolved.motor_current = 0.0
    }

    if (msg.motor_power !== undefined) {
      resolved.motor_power = msg.motor_power;
    }
    else {
      resolved.motor_power = 0.0
    }

    if (msg.commanded_velocity !== undefined) {
      resolved.commanded_velocity = msg.commanded_velocity;
    }
    else {
      resolved.commanded_velocity = 0.0
    }

    if (msg.measured_velocity !== undefined) {
      resolved.measured_velocity = msg.measured_velocity;
    }
    else {
      resolved.measured_velocity = 0.0
    }

    if (msg.measured_position !== undefined) {
      resolved.measured_position = msg.measured_position;
    }
    else {
      resolved.measured_position = 0.0
    }

    if (msg.supply_voltage !== undefined) {
      resolved.supply_voltage = msg.supply_voltage;
    }
    else {
      resolved.supply_voltage = 0.0
    }

    if (msg.supply_current !== undefined) {
      resolved.supply_current = msg.supply_current;
    }
    else {
      resolved.supply_current = 0.0
    }

    if (msg.motor_temperature !== undefined) {
      resolved.motor_temperature = msg.motor_temperature;
    }
    else {
      resolved.motor_temperature = 0.0
    }

    if (msg.channel_temperature !== undefined) {
      resolved.channel_temperature = msg.channel_temperature;
    }
    else {
      resolved.channel_temperature = 0.0
    }

    return resolved;
    }
};

module.exports = Feedback;
