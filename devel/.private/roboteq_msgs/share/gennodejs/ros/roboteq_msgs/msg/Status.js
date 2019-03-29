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

class Status {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.fault = null;
      this.status = null;
      this.ic_temperature = null;
      this.internal_voltage = null;
      this.adc_voltage = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('fault')) {
        this.fault = initObj.fault
      }
      else {
        this.fault = 0;
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
      if (initObj.hasOwnProperty('ic_temperature')) {
        this.ic_temperature = initObj.ic_temperature
      }
      else {
        this.ic_temperature = 0.0;
      }
      if (initObj.hasOwnProperty('internal_voltage')) {
        this.internal_voltage = initObj.internal_voltage
      }
      else {
        this.internal_voltage = 0.0;
      }
      if (initObj.hasOwnProperty('adc_voltage')) {
        this.adc_voltage = initObj.adc_voltage
      }
      else {
        this.adc_voltage = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Status
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [fault]
    bufferOffset = _serializer.uint8(obj.fault, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.uint8(obj.status, buffer, bufferOffset);
    // Serialize message field [ic_temperature]
    bufferOffset = _serializer.float32(obj.ic_temperature, buffer, bufferOffset);
    // Serialize message field [internal_voltage]
    bufferOffset = _serializer.float32(obj.internal_voltage, buffer, bufferOffset);
    // Serialize message field [adc_voltage]
    bufferOffset = _serializer.float32(obj.adc_voltage, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Status
    let len;
    let data = new Status(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [fault]
    data.fault = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [ic_temperature]
    data.ic_temperature = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [internal_voltage]
    data.internal_voltage = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [adc_voltage]
    data.adc_voltage = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roboteq_msgs/Status';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3a9b223fdfb0968255e25e5a859ac29';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # 10Hz status message for informational/diagnostics purposes
    Header header
    
    uint8 FAULT_OVERHEAT=1
    uint8 FAULT_OVERVOLTAGE=2
    uint8 FAULT_UNDERVOLTAGE=4
    uint8 FAULT_SHORT_CIRCUIT=8
    uint8 FAULT_EMERGENCY_STOP=16
    uint8 FAULT_SEPEX_EXCITATION_FAULT=32
    uint8 FAULT_MOSFET_FAILURE=64
    uint8 FAULT_STARTUP_CONFIG_FAULT=128
    uint8 fault
    
    uint8 STATUS_SERIAL_MODE=1
    uint8 STATUS_PULSE_MODE=2
    uint8 STATUS_ANALOG_MODE=4
    uint8 STATUS_POWER_STAGE_OFF=8
    uint8 STATUS_STALL_DETECTED=16
    uint8 STATUS_AT_LIMIT=32
    uint8 STATUS_MICROBASIC_SCRIPT_RUNNING=128
    uint8 status
    
    # Temperature of main logic chip (C)
    float32 ic_temperature
    
    # Internal supply and reference voltage (V)
    float32 internal_voltage
    float32 adc_voltage
    
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
    const resolved = new Status(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.fault !== undefined) {
      resolved.fault = msg.fault;
    }
    else {
      resolved.fault = 0
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    if (msg.ic_temperature !== undefined) {
      resolved.ic_temperature = msg.ic_temperature;
    }
    else {
      resolved.ic_temperature = 0.0
    }

    if (msg.internal_voltage !== undefined) {
      resolved.internal_voltage = msg.internal_voltage;
    }
    else {
      resolved.internal_voltage = 0.0
    }

    if (msg.adc_voltage !== undefined) {
      resolved.adc_voltage = msg.adc_voltage;
    }
    else {
      resolved.adc_voltage = 0.0
    }

    return resolved;
    }
};

// Constants for message
Status.Constants = {
  FAULT_OVERHEAT: 1,
  FAULT_OVERVOLTAGE: 2,
  FAULT_UNDERVOLTAGE: 4,
  FAULT_SHORT_CIRCUIT: 8,
  FAULT_EMERGENCY_STOP: 16,
  FAULT_SEPEX_EXCITATION_FAULT: 32,
  FAULT_MOSFET_FAILURE: 64,
  FAULT_STARTUP_CONFIG_FAULT: 128,
  STATUS_SERIAL_MODE: 1,
  STATUS_PULSE_MODE: 2,
  STATUS_ANALOG_MODE: 4,
  STATUS_POWER_STAGE_OFF: 8,
  STATUS_STALL_DETECTED: 16,
  STATUS_AT_LIMIT: 32,
  STATUS_MICROBASIC_SCRIPT_RUNNING: 128,
}

module.exports = Status;
