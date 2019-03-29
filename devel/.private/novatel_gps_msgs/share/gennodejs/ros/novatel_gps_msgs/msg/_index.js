
"use strict";

let Range = require('./Range.js');
let NovatelReceiverStatus = require('./NovatelReceiverStatus.js');
let Trackstat = require('./Trackstat.js');
let Time = require('./Time.js');
let NovatelExtendedSolutionStatus = require('./NovatelExtendedSolutionStatus.js');
let Gpgga = require('./Gpgga.js');
let Insstdev = require('./Insstdev.js');
let NovatelMessageHeader = require('./NovatelMessageHeader.js');
let Inspva = require('./Inspva.js');
let Gpgsv = require('./Gpgsv.js');
let Gpgsa = require('./Gpgsa.js');
let RangeInformation = require('./RangeInformation.js');
let Inscov = require('./Inscov.js');
let Satellite = require('./Satellite.js');
let Gprmc = require('./Gprmc.js');
let NovatelPosition = require('./NovatelPosition.js');
let NovatelCorrectedImuData = require('./NovatelCorrectedImuData.js');
let NovatelVelocity = require('./NovatelVelocity.js');
let TrackstatChannel = require('./TrackstatChannel.js');
let NovatelSignalMask = require('./NovatelSignalMask.js');

module.exports = {
  Range: Range,
  NovatelReceiverStatus: NovatelReceiverStatus,
  Trackstat: Trackstat,
  Time: Time,
  NovatelExtendedSolutionStatus: NovatelExtendedSolutionStatus,
  Gpgga: Gpgga,
  Insstdev: Insstdev,
  NovatelMessageHeader: NovatelMessageHeader,
  Inspva: Inspva,
  Gpgsv: Gpgsv,
  Gpgsa: Gpgsa,
  RangeInformation: RangeInformation,
  Inscov: Inscov,
  Satellite: Satellite,
  Gprmc: Gprmc,
  NovatelPosition: NovatelPosition,
  NovatelCorrectedImuData: NovatelCorrectedImuData,
  NovatelVelocity: NovatelVelocity,
  TrackstatChannel: TrackstatChannel,
  NovatelSignalMask: NovatelSignalMask,
};
