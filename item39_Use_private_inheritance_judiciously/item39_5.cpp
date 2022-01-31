// 一种激进的情况涉及空间最优化，可能会促使你选择“private继承”而不是“继承+复合”
// 也就是EBO（empty base optimization，空白基类最优化）的情况

// 现实中的empty class并不是真正的empty。虽然它们从未拥有non-static成员变量，
// 却往往内含typedefs,enums,static成员变量，或non-virtual函数。
// 举例：STL就有许多技术用途的empty class，比如unary_function 和 binary_function这两个基类

#include <iostream>
using namespace std;

class Empty{}; //大多数编译器中sizeof(Empty)=1
               //因为面对“大小为0的独立（非附属）对象”，C++会安插一个char到空对象内

class HoldsAnInt: private Empty{ //派生类的基类并非独立（非附属）。所以大小为零。
private:
    int x; //4
};

int main() {
    cout << "sizeof(Empty) = " << sizeof(Empty) << endl; //1
    cout << "sizeof(HoldsAnInt) = " << sizeof(HoldsAnInt) << endl; //4 //即sizeof(int)
}