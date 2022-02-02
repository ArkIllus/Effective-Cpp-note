// 为驳回编译器自动（暗自）提供的机能（即默认自动生成函数），
// 1.可将相应的成员函数声明为private并且不予实现。
// 2.或者设置成delete的，
// 3.或者private继承一个Uncopyable的base class。


// 下面的例子禁用copy构造函数、copy assignment操作符

// 1.可将相应的成员函数声明为private并且不予实现。
class HomeForSale{
public:
    HomeForSale(){};
private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&); //仅声明，没有定义（不会报错嗷）
};

int main() {
    HomeForSale homeForSale1;
    // HomeForSale homeForSale2(homeForSale1); //错误 "HomeForSale::HomeForSale(const HomeForSale &)" (已声明 所在行数:14) 不可访问
}

// C++ iostream程序库中就是这样阻止copying拷贝行为的。