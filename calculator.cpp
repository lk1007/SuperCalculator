#include <stack>
#include <algorithm>
#include <string>
#include "calculator.h"
using namespace std;

#define isNum(i) (i >= 0 && i < expr.size() && expr.at(i) >= '0' && expr.at(i) <= '9' )

Node* exprToTree(std::string expr){
    expr.erase(remove(expr.begin(),expr.end(), ' '), expr.end());
    Node* start = nullptr;
    int numStart = 0;
    int numEnd = 0;
    Node* op = nullptr;
    for(int i = 0; i < expr.size(); i++){
        if(isNum(i) && i != -1 && !isNum(i-1))
            numStart = i;
        if(i == expr.size()-1){
            Node* num = op->addChild(stof(expr.substr(numStart,i)));
            start->getHead()->printTree();
        }
        if(!isNum(i)){
            //if first number, make new node and make operator a parent
            if(numEnd == 0){
                start = new Node(stof(expr.substr(numStart,i)));
                op = new Node(expr.at(i));
                start->addParent(op);
            }
            //if another number, make child of previous operator and parent the new operator
            else{
                Node* num = op->addChild(stof(expr.substr(numStart,i)));
                op = new Node(expr.at(i));
            cout << i << endl;
                num->addParent(op);
            cout << i << endl;
            }
            numEnd = i; 
        }
    }
    return start->getHead();
}
float Calculator::doOperation(int num1, int num2, char op){
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
    Node* head = exprToTree(expr);
    return head->evalTree(*this);
}
/**
 * @brief Start of calculator program. Takes in expression and returns result of expression 
 * 
 */
void Calculator::calcMain(){
   string expr;
   cout << "Input your expression to calculate: ";
   getline (cin, expr);
   //expr = "11 * 11 + 11 * 22";
   expr.erase(remove(expr.begin(),expr.end(), ' '), expr.end());
   float result = parse(expr);
   cout <<  "answer: " << result << endl;
}
float Calculator::calcTest(string expr){
    return this->parse(expr);
}
void Calculator::showHistory(){
    std::cout << "history: \n";
    for(int i = 0; i < history.size(); i++){
        std::cout << "\t" << history.at(i) << "\n";
    }
}
Calculator::Calculator(){
}