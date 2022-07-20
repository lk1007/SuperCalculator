#include <string>
#include "func.h"
using namespace std;
int Calculator::add(int a, int b){
    int result = a+b;
    history.push_back(result);
    return result;
}
int Calculator::sub(int a, int b){
    int result = a+b;
    history.push_back(result);
    return result;
}
int Calculator::mult(int a, int b){
    int result = a+b;
    history.push_back(result);
    return result;
}
int Calculator::div(int a, int b){
    int result = a+b;
    history.push_back(result);
    return result;
}
void Calculator::operation(){
   string expr = "Liam";
   cout << expr << endl;
}
void Calculator::showHistory(){
    std::cout << "history: \n";
    for(int i = 0; i < history.size(); i++){
        std::cout << "\t" << history.at(i) << "\n";
    }

}
Calculator::Calculator(){
}