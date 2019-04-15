
"use strict";

let NovatelPosition = require('./NovatelPosition.js');
let RangeInformation = require('./RangeInformation.js');
let Inspva = require('./Inspva.js');
let NovatelExtendedSolutionStatus = require('./NovatelExtendedSolutionStatus.js');
let NovatelVelocity = require('./NovatelVelocity.js');
let TrackstatChannel = require('./TrackstatChannel.js');
let Range = require('./Range.js');
let Gprmc = require('./Gprmc.js');
let NovatelSignalMask = require('./NovatelSignalMask.js');
let Satellite = require('./Satellite.js');
let NovatelCorrectedImuData = require('./NovatelCorrectedImuData.js');
let Insstdev = require('./Insstdev.js');
let Time = require('./Time.js');
let Trackstat = require('./Trackstat.js');
let Gpgga = require('./Gpgga.js');
let NovatelMessageHeader = require('./NovatelMessageHeader.js');
let NovatelReceiverStatus = require('./NovatelReceiverStatus.js');
let Gpgsv = require('./Gpgsv.js');
let Inscov = require('./Inscov.js');
let Gpgsa = require('./Gpgsa.js');

module.exports = {
  NovatelPosition: NovatelPosition,
  RangeInformation: RangeInformation,
  Inspva: Inspva,
  NovatelExtendedSolutionStatus: NovatelExtendedSolutionStatus,
  NovatelVelocity: NovatelVelocity,
  TrackstatChannel: TrackstatChannel,
  Range: Range,
  Gprmc: Gprmc,
  NovatelSignalMask: NovatelSignalMask,
  Satellite: Satellite,
  NovatelCorrectedImuData: NovatelCorrectedImuData,
  Insstdev: Insstdev,
  Time: Time,
  Trackstat: Trackstat,
  Gpgga: Gpgga,
  NovatelMessageHeader: NovatelMessageHeader,
  NovatelReceiverStatus: NovatelReceiverStatus,
  Gpgsv: Gpgsv,
  Inscov: Inscov,
  Gpgsa: Gpgsa,
};
