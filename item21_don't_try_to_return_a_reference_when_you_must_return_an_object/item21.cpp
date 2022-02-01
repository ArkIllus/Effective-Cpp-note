// 有理数类的乘法
class Rational{
public:
    Rational(int numerator = 0, int denominator = 1): n(numerator), d(denominator){}
private:
    int n, d; //分子 分母
    //友元
    friend const Rational operator*(const Rational& lhs, const Rational& rhs); //返回一个对象，正确
    // friend const Rational& operator*(const Rational& lhs, const Rational& rhs); //返回一个引用，错误
};

// ===========operator* 必须返回一个对象，而不是引用。===========

// ===========假如我们返回一个引用===========
// 引用一定要绑定一个既有的对象，而在诸如
// Rational c = a * b; 之前并不存在一个数值同c的对象
//
// 那么operator*如果要返回一个引用，必须自己创建那个Rational对象。
// 创建对象有2种途径：
// 1.在Stack空间创建，比如
// const Rational& operator*(const Rational& lhs, const Rational& rhs) {
//     Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
//     return result;
// }
// 这个引用指向一个local对象，local对象在函数退出前被销毁了，因此一旦使用这个返回的引用就会发生“行为未定义”
//
// 2.在heap空间创建，比如
// const Rational& operator*(const Rational& lhs, const Rational& rhs) {
//     Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
//     return *result;
// }
// 那么问题是：谁来对这个new出来的对象实施delete?
//
// 3.即使使用定义于函数内部的static对象，比如
// const Rational& operator*(const Rational& lhs, const Rational& rhs) {
//     static Rational result;
//     result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);
//     return result;
// }
// 还是会出问题，比如再写一个operator==，((a*b) == (c*d))总是true，因为(a*b)和(c*d)返回的引用永远是
// static Rational对象的“现值”

// ===========综上所述，operator* 必须返回一个对象，那么正确写法就是返回一个新对象：===========
inline const Rational operator* (const Rational& lhs, const Rational& rhs){
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
// 当然这里有返回值的构造成本和析构成本。但是1.很多时候这个成本不大，是为了获得正确行为的小小代价。
// 2.C++编译器允许实现着施行最优化，因此某些情况下构造和析构可被安全地消除。