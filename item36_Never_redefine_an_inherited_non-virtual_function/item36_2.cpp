// non-virtual函数是静态绑定（statically bound）
// virtual函数是动态绑定（dynamically bound）
// 所以会有以下现象：

#include <iostream>
using namespace std;

class B {
public:
    virtual void mf() {cout << "B::mf()" << endl;}
};

class D: public B {
public:
    virtual void mf() {cout << "D::mf()" << endl;} //隐藏（hides）了B::mf
};

int main() {
    D x;

    B* pB = &x;
    pB->mf(); //调用D::mf

    D* pD = &x;
    pD->mf();  //调用D::mf
}

// 不论通过pB或pD调用mf，都会导致调用D::mf，因为pB和pD真正指向的都是一个类型为D的对象。