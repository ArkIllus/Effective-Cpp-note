// 对于C++中的C语言部分来说，初始化变量有可能会导致runtime（运行期）的效率变低，那么就不保证初始化。（例如C部分的array）
// 但是C++中的非C部分规则就有所变化（保证初始化？）（例如STL部分的vector）

// 最佳办法是：永远在使用对象之前先将它们初始化。
// 【为内置类型进行手动初始化，因为C++不保证初始化它们】。

// 注意区分【初始化】和【赋值】的关系
// 初始化的效率高，赋值的效率低，
// 初始化的次序：base classes早于其derived classes被初始化，而class的成员变量总是以其声明次序被初始化。

// 构造函数的比较好的写法是，使用【成员初值列】（member initialization list）替换赋值动作。
// 比如：
class A{
    int x_;
    char c_;
public:
    A(int x, char c): x_(x), c_(c){}
};