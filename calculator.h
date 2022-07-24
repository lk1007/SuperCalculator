#include <vector>
#include <iostream>
#ifndef FUNC_H
class Calculator{
    public:
        void showHistory();
        void operation();
        Calculator();
    private:
        std::vector<float> history;
        float eval(std::string& expr, int opLoc);
        float parse(std::string& expr);
        float add(float a, float b);
        float sub(float a, float b);
        float mult(float a, float b);
        float div(float a, float b);
    };
struct Node{
    bool isOp;
    std::vector<Node> children;
};
#endif