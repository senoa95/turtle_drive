
"use strict";

let Gpgga = require('./Gpgga.js');
let Gpgsa = require('./Gpgsa.js');
let NovatelVelocity = require('./NovatelVelocity.js');
let NovatelExtendedSolutionStatus = require('./NovatelExtendedSolutionStatus.js');
let Gprmc = require('./Gprmc.js');
let Trackstat = require('./Trackstat.js');
let Insstdev = require('./Insstdev.js');
let NovatelPosition = require('./NovatelPosition.js');
let Satellite = require('./Satellite.js');
let TrackstatChannel = require('./TrackstatChannel.js');
let Time = require('./Time.js');
let NovatelMessageHeader = require('./NovatelMessageHeader.js');
let NovatelReceiverStatus = require('./NovatelReceiverStatus.js');
let Gpgsv = require('./Gpgsv.js');
let RangeInformation = require('./RangeInformation.js');
let Inscov = require('./Inscov.js');
let Range = require('./Range.js');
let NovatelSignalMask = require('./NovatelSignalMask.js');
let Inspva = require('./Inspva.js');
let NovatelCorrectedImuData = require('./NovatelCorrectedImuData.js');

module.exports = {
  Gpgga: Gpgga,
  Gpgsa: Gpgsa,
  NovatelVelocity: NovatelVelocity,
  NovatelExtendedSolutionStatus: NovatelExtendedSolutionStatus,
  Gprmc: Gprmc,
  Trackstat: Trackstat,
  Insstdev: Insstdev,
  NovatelPosition: NovatelPosition,
  Satellite: Satellite,
  TrackstatChannel: TrackstatChannel,
  Time: Time,
  NovatelMessageHeader: NovatelMessageHeader,
  NovatelReceiverStatus: NovatelReceiverStatus,
  Gpgsv: Gpgsv,
  RangeInformation: RangeInformation,
  Inscov: Inscov,
  Range: Range,
  NovatelSignalMask: NovatelSignalMask,
  Inspva: Inspva,
  NovatelCorrectedImuData: NovatelCorrectedImuData,
};
