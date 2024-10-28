#include "StringCalculator.h"
#include <gtest/gtest.h>

class StringCalculatorAddFixture:public testing::Test {
  protected:
    StringCalculator *objUnderTest;
    void SetUp() override {
      objUnderTest = new StringCalculator();
    }
    void TearDown() override {
      delete objUnderTest;
    }
};

TEST_F(StringCalculatorAddFixture, Returns_0_for_zero) {
  int expectedValue = 0;
  string input = "0";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}
