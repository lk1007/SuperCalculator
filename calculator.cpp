#include <algorithm>
#include <string>
#include "calculator.h"
using namespace std;
float Calculator::add(float a, float b){
    float result = a+b;
    history.push_back(result);
    return result;
}
float Calculator::sub(float a, float b){
    float result = a+b;
    history.push_back(result);
    return result;
}
float Calculator::mult(float a, float b){
    float result = a+b;
    history.push_back(result);
    return result;
}
float Calculator::div(float a, float b){
    float result = a+b;
    history.push_back(result);
    return result;
}
#define inRange(i)
#define isNum(i) (i >= 0 && i < expr.size() && expr.at(i) >= '0' && expr.at(i) <= '9' )
float Calculator::eval(string& expr, int opLoc){
    int i = opLoc-1;
    int j = opLoc+1;
    char op = expr.at(opLoc);
    cout << i << ' ' << j << endl;
    while(isNum(i) || isNum(j)){
        if(isNum(i-1))
            i--;
        if(isNum(j+1))
            j++;
        if(i == 0 && j == expr.size() - 1)
            break;
    }
    cout << "going2" << endl;
    float num1 = stof(expr.substr(i,opLoc));
    float num2 = stof(expr.substr(opLoc+1,expr.size()-1));
    switch (op){
        case '+':
            return this->add(num1,num2);
        case '-':
            return this->sub(num1,num2);
        case '*':
            return this->mult(num1,num2);
        case '/':
            return this->div(num1,num2);
        default:
            return 0;
        }
}
/**
 * @brief 
 * Parses expression, calculates the expression and returns the result 
 * @param expr 
 * @return float 
 */
float Calculator::parse(string& expr){
    int i = 0;
    return this->eval(expr, 2);
}
/**
 * @brief Start of calculator program. Takes in expression and returns result of expression 
 * 
 */
void Calculator::operation(){
   string expr;
   cout << "Input your expression to calculate: ";
   getline (cin, expr);
   expr.erase(remove(expr.begin(),expr.end(), ' '), expr.end());
   float result = parse(expr);
   cout <<  "answer: " << result << endl;
}
void Calculator::showHistory(){
    std::cout << "history: \n";
    for(int i = 0; i < history.size(); i++){
        std::cout << "\t" << history.at(i) << "\n";
    }
}
Calculator::Calculator(){
}