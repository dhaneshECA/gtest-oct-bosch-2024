#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(when_passed_a_single_number, Returns_0_for_zero) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 0;

  //Act
  int actualValue = objUnderTest.Add("0");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_a_single_number, Returns_0_for_empty_string) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 0;

  //Act
  int actualValue = objUnderTest.Add("");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_a_single_number, Returns_1_for_one) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 0;

  //Act
  int actualValue = objUnderTest.Add("1");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_two_comma_delimited_numbers, Returns_their_sum) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 3;

  //Act
  int actualValue = objUnderTest.Add("1,2");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_multiple_comma_delimited_numbers, Returns_their_sum) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 6;

  //Act
  int actualValue = objUnderTest.Add("1,2,3");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}


