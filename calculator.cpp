#include <algorithm>
#include <string>
#include "func.h"
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
float Calculator::parse(string& expr){
    int i = 0;
    while(expr.at(i) >= '0' && expr.at(i) <= '9')
        i++;
    float num1 = stof(expr.substr(0,i));
    int op = expr.at(i);
    float num2 = stof(expr.substr(i,expr.size()));
    switch (op){
        case '+':
            return add(num1,num2);

    }
    return num1;
}
void Calculator::operation(){
   string expr;
   cout << "Input your expression to calculate: ";
   getline (cin, expr);
   expr.erase(remove(expr.begin(),expr.end(), ' '), expr.end());
   float result = parse(expr);
   cout << result << endl;
}
void Calculator::showHistory(){
    std::cout << "history: \n";
    for(int i = 0; i < history.size(); i++){
        std::cout << "\t" << history.at(i) << "\n";
    }

}
Calculator::Calculator(){
}