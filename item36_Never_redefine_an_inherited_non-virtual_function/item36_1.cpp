// non-virtual函数是静态绑定（statically bound）
// virtual函数是动态绑定（dynamically bound）
// 所以会有以下现象：

#include <iostream>
using namespace std;

class B {
public:
    void mf() {cout << "B::mf()" << endl;}
};

class D: public B {
public:
    void mf() {cout << "D::mf()" << endl;} //隐藏（hides）了B::mf
};

int main() {
    D x;

    B* pB = &x;
    pB->mf(); //调用B::mf

    D* pD = &x;
    pD->mf();  //调用D::mf
}

// pB被声明为一个pointer-to-B,通过pB调用的non-virtual函数永远是B所定义的版本，即使pB指向一个类型为“B的派生类”的对象。