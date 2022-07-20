#include <vector>
#include <iostream>
#ifndef FUNC_H
class Calculator{
    public:
        int add(int a, int b);
        int sub(int a, int b);
        int mult(int a, int b);
        int div(int a, int b);
        void showHistory();
        void operation();
        Calculator();
    private:
        std::vector<int> history;
    };
#endif
