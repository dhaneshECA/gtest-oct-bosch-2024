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
  int expectedValue = 1;

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

TEST(when_delimited_with_newline_and_comma, Returns_their_sum) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 6;

  //Act
  int actualValue = objUnderTest.Add("1\n2,3");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_delimited_with_newline_and_comma, Returns_the_sum_based_on_that_delimiter) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 3;

  //Act
  int actualValue = objUnderTest.Add("//;\n1;2");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_numbers_over_1000, Ignores_them) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 45;

  //Act
  int actualValue = objUnderTest.Add("42,1001,3");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_multicharacter_delimiter, Uses_that_delimiter_to_sum_values) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 13;

  //Act
  int actualValue = objUnderTest.Add("//[***]\n8***2***3");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_multiple_delimiters, Sums_on_each_delimiter) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 9;

  //Act
  int actualValue = objUnderTest.Add("//[*][%]\n4*2%3");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}

TEST(when_passed_multiple_multicharacter_delimiters, Sums_on_each_delimiter) {
  // Arrange
  StringCalculator objUnderTest;
  int expectedValue = 14;

  //Act
  int actualValue = objUnderTest.Add("//[**][%^]\n4**1%^9");
  
  //Assert
  EXPECT_EQ(expectedValue, actualValue);
}






