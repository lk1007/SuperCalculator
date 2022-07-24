#include <vector>
#include "calculator.h"
using namespace std;
float Calculator::add(float a, float b){
    float result = a+b;
    history.push_back(result);
    return result;
}
float Calculator::sub(float a, float b){
    float result = a-b;
    history.push_back(result);
    return result;
}
float Calculator::mult(float a, float b){
    float result = a*b;
    history.push_back(result);
    return result;
}
float Calculator::div(float a, float b){
    float result = a/b;
    history.push_back(result);
    return result;
}