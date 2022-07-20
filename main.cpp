#include <iostream>
#include "func.h"
int main(){
    Calculator calc = Calculator();
    std::vector<int> calculations;
    calc.operation();
    calc.showHistory();
    return 0;
}