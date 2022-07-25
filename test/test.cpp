#include "../calculator.h"
#include <gtest/gtest.h>
TEST(exampTest, addExpr){
    Calculator calc;
    float n = calc.calcTest("1 + 1");
    ASSERT_EQ(n, 2);
}
TEST(exampTest, addExpr2){
    Calculator calc;
    float n = calc.calcTest("1 + 2*4");
    ASSERT_EQ(n, 14);
}