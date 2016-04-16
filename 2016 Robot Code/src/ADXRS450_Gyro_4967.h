/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2015-2016. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "GyroBase.h"
#include "Notifier.h"
#include "SPI.h"
#include "HAL/cpp/priority_mutex.h"

#include <memory>

/**
 * Use a rate gyro to return the robots heading relative to a starting position.
 * The Gyro class tracks the robots heading based on the starting position. As
 * the robot rotates the new heading is computed by integrating the rate of
 * rotation returned by the sensor. When the class is instantiated, it does a
 * short calibration routine where it samples the gyro while at rest to
 * determine the default offset. This is subtracted from each sample to
 * determine the heading.
 *
 * This class is for the digital ADXRS450 gyro sensor that connects via SPI.
 */
class ADXRS450_Gyro_4967 : public GyroBase {
 public:
  ADXRS450_Gyro_4967();
  explicit ADXRS450_Gyro_4967(SPI::Port port);
  virtual ~ADXRS450_Gyro_4967() = default;

  float GetAngle() const override;
  double GetRate() const override;
  void Reset() override;
  void Calibrate() override;
  void NullAdjust(bool begin);

 private:
  SPI m_spi;
  int32_t m_centerValue = 0;

  uint16_t ReadRegister(uint8_t reg);
};