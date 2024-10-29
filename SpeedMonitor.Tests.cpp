#include "SpeedMonitor.h"
#include <gtest/gtest.h>

//Fixture Class
class SpeedMonitorFixture : public testing::Test {
  protected:
    SpeedMonitor* objUnderTest;
    IMessageCommunicator* messageCommunicator;
    ISpeedSensor* speedSensor;
  void SetUp() override {
    objUnderTest = new StringCalculator();
    messageCommunicator = new IOTCloudCommunicator();
    speedSensor = new BNFSpeedSensor();
  }

};
