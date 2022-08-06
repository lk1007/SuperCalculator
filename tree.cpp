#include <stack>
#include <algorithm>
#include <string>
#include "calculator.h"
#include <cstdio>
using namespace std;
Node::Node(float val){
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->val = val;
    if(val == '*' || val == '/') this->priority = 2;
    else if(val == '+' || val == '-') this->priority = 1;
    else this->priority == 0;
}
Node::Node(int val){
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->val = val;
    if(val == '*' || val == '/') this->priority = 2;
    else if(val == '+' || val == '-') this->priority = 1;
    else this->priority == 0;
}
//void Node::makeParent(Node& newParent){
//    if(!newParent.left) newParent.left = this;
//    else if(!newParent.right) newParent.right = this;
//}
Node* Node::getHead(){
    if(!this->parent) return this;
    else return this->parent->getHead();
}
float Node::evalTree(Calculator& calc){
    if(!this->left || !this->right) return this->val;
    float n = calc.doOperation(this->left->evalTree(calc),this->right->evalTree(calc), this->val);
    delete(this);
    return n;
}

Node* Node::addChild(Node* child){
    if(!this->left){ 
        this->left = child; 
        child->parent = this;
        return child;
    }else if(!this->right) {
        this->right = child; 
        child->parent = this;
        return child;
    }else throw std::runtime_error("Children filled in Node");
}
Node* Node::addChild(int val){
    if(!this->left){ 
        Node* child = new Node(val);
        this->left = child; 
        child->parent = this;
        return child;
    }else if(!this->right) {
        Node* child = new Node(val);
        this->right = child; 
        child->parent = this;
        return child;
    }else throw std::runtime_error("Children filled in Node");

}
Node* Node::addChild(float val){
    if(!this->left){ 
        Node* child = new Node(val);
        this->right = child; 
        child->parent = this;
        return child;
    }else if(!this->right) {
        Node* child = new Node(val);
        this->right = child; 
        child->parent = this;
        return child;
    }else throw std::runtime_error("Children filled in Node");
}
Node* Node::removeChild(Node* child){
    if(this->left == child)
        this->left = nullptr;
    else if(this->right == child)
        this->right = nullptr;
    else throw std::runtime_error("Not a valid child");
    return child;
}
Node* Node::addParent(Node* newParent){
    if(this->parent){
        if(newParent->priority  > this->parent->priority){
            this->parent->removeChild(this);
            this->parent->addChild(newParent);
            newParent->addChild(this); 
        }
        //if same priority, make new parent the overall parent
        else
            this->parent->addParent(newParent);
    }
    //if no parent
    else{
        if(this->priority > newParent->priority)
            this->addChild(newParent);
        else
            newParent->addChild(this);
    return newParent; 
    }
}

inline void charPrint(float n){
    if( n== '*' || n == '+' || n == '-' || n == '/')
        printf(" %c \n",(char)n);
    else
        printf(" %d \n",(int)n);
}

void Node::printTreeAux(const string& prefix, bool isLeft){
        cout << prefix;
        if(this->parent)
            cout << (isLeft ? "├──" : "└──" );
        else
            cout << "   ";
        // print the value of the node
        charPrint(this->val);

        // enter the next tree level - left and right branch
        if(this->left)
            this->left->printTreeAux( prefix + (isLeft ? "│   " : "    "), true);
        if(this->right)
            this->right->printTreeAux( prefix + (isLeft ? "│   " : "    "), false);
}

void Node::printTree()
{
    this->printTreeAux("" ,false);    
}

Node* sampleTree(){
    vector<int> values;
    Node* head = new Node('*');
    Node* ch1 = head->addChild('+');
    Node* ch2 = head->addChild('+');
    Node* ch11 = ch1->addChild(3);
    Node* ch12 = ch1->addChild(6);
    Node* ch21 = ch2->addChild(4);
    Node* ch22 = ch2->addChild(5);
    return head;
}