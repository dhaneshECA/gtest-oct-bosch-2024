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

TEST_F(StringCalculatorAddFixture, Returns_0_for_empty_string) {
  int expectedValue = 0;
  string input = "";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Returns_1_for_one) {
  int expectedValue = 1;
  string input = "1";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Returns_their_sum_when_passed_two_comma_delimited_numbers) {
  int expectedValue = 3;
  string input = "1,2";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Returns_their_sum_when_passed_multiple_comma_delimited_numbers) {
  int expectedValue = 6;
  string input = "1,2,3";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Returns_their_sum_when_delimited_with_newline_and_comma) {
  int expectedValue = 6;
  string input = "1\n2,3";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Returns_the_sum_based_on_that_delimiter_when_delimited_with_newline_and_comma) {
  int expectedValue = 3;
  string input = "//;\n1;2";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Ignores_them_when_passed_numbers_over_1000) {
  int expectedValue = 45;
  string input = "42,1001,3";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Uses_that_delimiter_to_sum_values_when_passed_multicharacter_delimiter) {
  int expectedValue = 13;
  string input = "//[***]\n8***2***3";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Sums_on_each_delimiter_when_passed_multiple_delimiters) {
  int expectedValue = 9;
  string input = "//[*][%]\n4*2%3";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Sums_on_each_delimiter_when_passed_multiple_multicharacter_delimiters) {
  int expectedValue = 14;
  string input = "//[**][%^]\n4**1%^9";
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Throws_an_exception_listing_invalid_values_when_passed_negative_numbers) {
  EXPECT_THROW(objUnderTest->Add("1,-2,-4,5"), std::invalid_argument);
}

