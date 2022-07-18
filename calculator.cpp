#include <vector>
class Calculator{
    public:
        int add(int a, int b);
        int sub(int a, int b);
        int mult(int a, int b);
        int div(int a, int b);
        Calculator();
    private:
        std::vector<int> history;
    };
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
Calculator::Calculator(){

}