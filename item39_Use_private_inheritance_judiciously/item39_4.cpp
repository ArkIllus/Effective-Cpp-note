// 一种激进的情况涉及空间最优化，可能会促使你选择“private继承”而不是“继承+复合”
// 也就是EBO（empty base optimization，空白基类最优化）的情况

#include <iostream>
using namespace std;

class Empty{}; //大多数编译器中sizeof(Empty)=1
               //因为面对“大小为0的独立（非附属）对象”，C++会安插一个char到空对象内

class HoldsAnInt{
private:
    int x; //4
    Empty e; //1+3=4
             //因为内存对齐（alignment），实际上被放大到足够存放一个int
};

int main() {
    cout << "sizeof(Empty) = " << sizeof(Empty) << endl; //1
    cout << "sizeof(HoldsAnInt) = " << sizeof(HoldsAnInt) << endl; //8
}