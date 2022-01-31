// Widget复用Timer的代码
//
// 使用public继承并不恰当，因为Widget不是一个（is not a）Timer，
// 如果这样做客户就能对一个Widget对象调用onTick，然而onTick不应该是Widget接口的一部分，误导了客户。
//
// 方式一：private继承
// private继承意味着is-implemented-in-terms-of（根据某物实现出）
// 这和复合（composition）的意义相同。大多数情况下我们尽可能使用复合，必要时才使用private继承。

class Timer {
public:
    explicit Timer(int tickFrequency){}
    virtual void onTick() const; //定时器每滴答一次，此函数就被自动调用一次
    //...
};

class Widget: private Timer {
private:
    virtual void onTick() const; //查看Widget的数据等等
    //...
};

int main() {
}