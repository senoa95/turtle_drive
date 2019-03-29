
"use strict";

let NovatelMessageHeader = require('./NovatelMessageHeader.js');
let RangeInformation = require('./RangeInformation.js');
let Satellite = require('./Satellite.js');
let Insstdev = require('./Insstdev.js');
let Gpgsa = require('./Gpgsa.js');
let NovatelVelocity = require('./NovatelVelocity.js');
let Gprmc = require('./Gprmc.js');
let Inscov = require('./Inscov.js');
let NovatelPosition = require('./NovatelPosition.js');
let NovatelCorrectedImuData = require('./NovatelCorrectedImuData.js');
let NovatelExtendedSolutionStatus = require('./NovatelExtendedSolutionStatus.js');
let NovatelReceiverStatus = require('./NovatelReceiverStatus.js');
let Gpgga = require('./Gpgga.js');
let NovatelSignalMask = require('./NovatelSignalMask.js');
let Time = require('./Time.js');
let Range = require('./Range.js');
let TrackstatChannel = require('./TrackstatChannel.js');
let Trackstat = require('./Trackstat.js');
let Inspva = require('./Inspva.js');
let Gpgsv = require('./Gpgsv.js');

module.exports = {
  NovatelMessageHeader: NovatelMessageHeader,
  RangeInformation: RangeInformation,
  Satellite: Satellite,
  Insstdev: Insstdev,
  Gpgsa: Gpgsa,
  NovatelVelocity: NovatelVelocity,
  Gprmc: Gprmc,
  Inscov: Inscov,
  NovatelPosition: NovatelPosition,
  NovatelCorrectedImuData: NovatelCorrectedImuData,
  NovatelExtendedSolutionStatus: NovatelExtendedSolutionStatus,
  NovatelReceiverStatus: NovatelReceiverStatus,
  Gpgga: Gpgga,
  NovatelSignalMask: NovatelSignalMask,
  Time: Time,
  Range: Range,
  TrackstatChannel: TrackstatChannel,
  Trackstat: Trackstat,
  Inspva: Inspva,
  Gpgsv: Gpgsv,
};
