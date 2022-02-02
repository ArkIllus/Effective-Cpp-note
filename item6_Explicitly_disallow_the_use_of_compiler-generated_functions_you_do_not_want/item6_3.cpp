// 为驳回编译器自动（暗自）提供的机能（即默认自动生成函数），
// 1.可将相应的成员函数声明为private并且不予实现。
// 2.或者设置成delete的，
// 3.或者private继承一个Uncopyable的base class。


// 下面的例子禁用copy构造函数、copy assignment操作符

// 3.或者private继承一个Uncopyable的base class。
class Uncopyable {
protected:
    Uncopyable(){}
    ~Uncopyable(){} //析构函数不一定要是virtual
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale: private Uncopyable{ //不一定要public继承
    // ...
};

int main() {
    HomeForSale homeForSale1;
    // HomeForSale homeForSale2(homeForSale1); //错误 无法引用 函数 "HomeForSale::HomeForSale(const HomeForSale &)" (已隐式声明) -- 它是已删除的函数
}