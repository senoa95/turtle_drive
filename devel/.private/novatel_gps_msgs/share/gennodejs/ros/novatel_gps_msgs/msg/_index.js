
"use strict";

let NovatelVelocity = require('./NovatelVelocity.js');
let Inspva = require('./Inspva.js');
let NovatelReceiverStatus = require('./NovatelReceiverStatus.js');
let NovatelMessageHeader = require('./NovatelMessageHeader.js');
let Gpgsa = require('./Gpgsa.js');
let NovatelExtendedSolutionStatus = require('./NovatelExtendedSolutionStatus.js');
let Gprmc = require('./Gprmc.js');
let Satellite = require('./Satellite.js');
let NovatelPosition = require('./NovatelPosition.js');
let Gpgga = require('./Gpgga.js');
let NovatelCorrectedImuData = require('./NovatelCorrectedImuData.js');
let Time = require('./Time.js');
let Trackstat = require('./Trackstat.js');
let Range = require('./Range.js');
let NovatelSignalMask = require('./NovatelSignalMask.js');
let Insstdev = require('./Insstdev.js');
let RangeInformation = require('./RangeInformation.js');
let Inscov = require('./Inscov.js');
let TrackstatChannel = require('./TrackstatChannel.js');
let Gpgsv = require('./Gpgsv.js');

module.exports = {
  NovatelVelocity: NovatelVelocity,
  Inspva: Inspva,
  NovatelReceiverStatus: NovatelReceiverStatus,
  NovatelMessageHeader: NovatelMessageHeader,
  Gpgsa: Gpgsa,
  NovatelExtendedSolutionStatus: NovatelExtendedSolutionStatus,
  Gprmc: Gprmc,
  Satellite: Satellite,
  NovatelPosition: NovatelPosition,
  Gpgga: Gpgga,
  NovatelCorrectedImuData: NovatelCorrectedImuData,
  Time: Time,
  Trackstat: Trackstat,
  Range: Range,
  NovatelSignalMask: NovatelSignalMask,
  Insstdev: Insstdev,
  RangeInformation: RangeInformation,
  Inscov: Inscov,
  TrackstatChannel: TrackstatChannel,
  Gpgsv: Gpgsv,
};
