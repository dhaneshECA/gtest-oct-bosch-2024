#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>

//Fixture class
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

//Value Parameterized Fixture class
class StringCalculatorAddValueParamFixture: public StringCalculatorAddFixture, public testing::WithParamInterface<tuple<string,int>> {

};

INSTANTIATE_TEST_SUITE_P(ValidValuesDataSet,StringCalculatorAddValueParamFixture,testing::Values(
make_tuple("",0), make_tuple("0",0), make_tuple("1",1), make_tuple("1,2,3",6),
make_tuple("//;\n1;2", 3), make_tuple("//[***]\n8***2***3", 13), make_tuple("//[*][%]\n4*2%3",9), make_tuple("42,1001,3",45)
));

TEST_P(StringCalculatorAddValueParamFixture, DataDrivenTest) {
  string input = std::get<0>(GetParam());
  int expectedValue = std::get<1>(GetParam());
  int actualValue = objUnderTest->Add(input);
  EXPECT_EQ(expectedValue, actualValue);
}

TEST_F(StringCalculatorAddFixture, Throws_an_exception_listing_invalid_values_when_passed_negative_numbers) {
  string input = "1,-2,-4,5";
  EXPECT_THROW(objUnderTest->Add(input), std::invalid_argument);
}
