// Auto-generated. Do not edit!

// (in-package roboteq_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Command {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mode = null;
      this.setpoint = null;
    }
    else {
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('setpoint')) {
        this.setpoint = initObj.setpoint
      }
      else {
        this.setpoint = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Command
    // Serialize message field [mode]
    bufferOffset = _serializer.int8(obj.mode, buffer, bufferOffset);
    // Serialize message field [setpoint]
    bufferOffset = _serializer.float32(obj.setpoint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Command
    let len;
    let data = new Command(null);
    // Deserialize message field [mode]
    data.mode = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [setpoint]
    data.setpoint = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roboteq_msgs/Command';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9f57e6568807eb250db6d5bd382ee299';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    # Control whether the setpoint represents a velocity or position command.
    # Velocity is the default, but position may be used for fine-grained movements,
    # or active braking on an incline. Stopped is high-z (coasting).
    int8 MODE_STOPPED=-1
    int8 MODE_VELOCITY=0
    int8 MODE_POSITION=1
    int8 mode
    
    # Commanded velocity (rad/s) or position (rad) for the motor. Position uses
    # the same scale as measured_position in the Feedback message.
    float32 setpoint
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Command(null);
    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.setpoint !== undefined) {
      resolved.setpoint = msg.setpoint;
    }
    else {
      resolved.setpoint = 0.0
    }

    return resolved;
    }
};

// Constants for message
Command.Constants = {
  MODE_STOPPED: -1,
  MODE_VELOCITY: 0,
  MODE_POSITION: 1,
}

module.exports = Command;
