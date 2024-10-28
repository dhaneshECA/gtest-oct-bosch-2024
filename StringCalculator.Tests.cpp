#include "StringCalculator.h"
#include <gtest/gtest.h>

// Tests factorial of 0.
TEST(when_passed_a_single_number, Returns_0_for_zero) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 0;

  //Act
  int actualValue = objUnderTest.Add("0");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}


