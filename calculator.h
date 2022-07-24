#include <vector>
#include <iostream>
#ifndef CALCULATOR_H
class Calculator{
    public:
        void showHistory();
        void calcMain();
        float doOperation(int num1, int num2, char op);
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
class Node{
    private:
        float val;
        int priority;
        Node* parent;
        Node* left;
        Node* right;
    public:
        Node(float val);
        Node(int val);
        void printChildren(){
            if(this->left || this->right){
                std::cout << "node: " << (this) << std::endl; 
                std::cout << "\tleft: " << this->left << std::endl;
                std::cout << "\tright: " << this->right << std::endl;
            }
        }
        void printTree();
        Node* removeChild(Node* child);
        Node* getHead();
        Node* addParent(Node* parent);
        Node* addChild(Node* child);
        Node* addChild(int val);
        Node* addChild(float val);
        float evalTree(Calculator& calc);
};
Node* sampleTree();
Node* exprToTree(std::string expr);

#endif