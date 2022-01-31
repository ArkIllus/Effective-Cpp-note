// Widget复用Timer的代码
//
// 使用public继承并不恰当，因为Widget不是一个（is not a）Timer，
// 如果这样做客户就能对一个Widget对象调用onTick，然而onTick不应该是Widget接口的一部分，误导了客户。
//
// 方式二：嵌套式private类+public继承+复合
// private继承意味着is-implemented-in-terms-of（根据某物实现出）
// 这和复合（composition）的意义相同。大多数情况下我们尽可能使用复合，必要时才使用private继承。

// 选择方式二，不选择方式一的2个理由：
// 1.可以阻止派生类重新定义virtual函数（也就是Java的final和C#的sealed）
// （备注：但是现在C++也有final关键字了吧。。。）
// 2.将Widget的编译依存性降到最低，
// 如果将WidgetTimer移出Widget，而Widget内含一个指针指向一个WidgetTimer，
// Widget可以不再include与Timer有关的东西（比如Timer.h）

class Timer {
public:
    explicit Timer(int tickFrequency){}
    virtual void onTick() const; //定时器每滴答一次，此函数就被自动调用一次
    //...
};

class Widget {
private:
    class WidgetTimer: public Timer { //WidgetTimer是一个（is a）Timer
    public:
        virtual void onTick() const;
    };
    WidgetTimer timer;
    //...
};

int main() {
}