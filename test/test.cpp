#include "../calculator.h"
#include <gtest/gtest.h>
TEST(exampTest, addExpr){
    Calculator calc;
    float n = calc.calcTest("1 + 1");
    ASSERT_EQ(n, 2);
    n = calc.calcTest("1 - 2*4");
    ASSERT_EQ(n, -7);
    n = calc.calcTest("");
    ASSERT_EQ(n, 0);
    n = calc.calcTest("4/2 + 1 - 7*8 + 48/4 - 21/7");
    ASSERT_EQ(n, -44);
    n = calc.calcTest("         2 + 3   ");
    ASSERT_EQ(n, 5);
    n = calc.calcTest("2+7                  ");
    ASSERT_EQ(n, 9);
}