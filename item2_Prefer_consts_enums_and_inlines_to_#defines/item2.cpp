// 尽量以const, enum, inline替换#define 意味着“宁可以编译器替换预处理器”

#include <string>
#include <iostream>
using namespace std;

// #define RATIO 1.653
// 问题1.记号名称RATIO可能从未被编译器看见，可能从未进入记号表（symbol table）内
// 举例来说报错的时候可能就报1.653而不是RATIO
// 问题2.预处理器只会傻瓜式地替换，可能出现多份1.653，而改用常量就不会出现这种情况

const double Ratio = 1.653;
// 改用常量替换宏(#define)。


// 用常量替换宏(#define)的注意点
// 注意点1.常量指针（指向常量的const pointer，2个const）
const char* const authorName = "Sccot Meyers"; //*左边的const：被指物是常量；*右边的const：指针自身是常量
const std::string authorName2("Sccot Meyers"); //我们更建议用string代替const char*

// 注意点2.class专属常量
class GamePlayer{
    static const int NumTurns = 5; //常量声明式（static成员可以在其声明式上获得初值） 
                                   //static保证此常量最多只有一份
    int scores[NumTurns];
};

// 如果编译器不支持上面的写法（不允许static成员在其声明式上获得初值），也可以这么写：
class CostEstimate{
    static const double FudgeFactor; //（头文件内）声明
};
const double CostEstimate::FudgeFactor = 1.35; //（实现文件内）定义
// class GamePlayer2{
//     static const int NumTurns;
//     int scores[NumTurns]; //错误，因为此时NumTurns只声明，没有被定义
// };
// const int GamePlayer2::NumTurns = 1;
class GamePlayer3{
    enum{NumTurns=5}; //enum类型的值可以被当做int使用
    int scores[NumTurns];
};


void f(int x){}
void f(double x){}
void f(char x){}
//使用形式函数的宏(macro)是一个很糟糕的事
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
//即使加了这么多括号，还是可能出问题：
void test_macro() {
    cout << "很糟糕的形似函数的宏：" << endl;
    int a = 5, b = 0;
    CALL_WITH_MAX(++a, b); //a被累加2次
    cout << "a = " << a << ", b = " << b << endl;

    int a2 = 5, b2 = 0;
    CALL_WITH_MAX(++a2, b2+10);  //a2被累加1次
    cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
}

// 正确的做法是template inline函数，它可以获得宏带来的效率以及一般函数的所有可预料行为和类型安全性
template <typename T>
inline void callWithMax(const T& a, const T& b){
    f(a > b ? a : b);
}
void test_inline_template() {
    cout << "template inline函数：" << endl;
    int a = 5, b = 0;
    callWithMax(++a, b); //a被累加1次
    cout << "a = " << a << ", b = " << b << endl;

    int a2 = 5, b2 = 0;
    callWithMax(++a2, b2+10);  //a2被累加1次
    cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
}

int main() {
    test_macro();
    test_inline_template();
}