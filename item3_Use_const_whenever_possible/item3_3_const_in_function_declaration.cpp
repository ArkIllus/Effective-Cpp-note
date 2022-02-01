// const最具威力的用法是在函数声明时，如果将返回值设置成const，可以避免很多用户错误造成的意外。

// 下面我们来看看item21里出现的代码：
// 有理数类的乘法
class Rational{
public:
    Rational(int numerator = 0, int denominator = 1): n(numerator), d(denominator){}
private:
    int n, d; //分子 分母
    friend const Rational operator*(const Rational& lhs, const Rational& rhs); //返回一个对象，正确
};
inline const Rational operator* (const Rational& lhs, const Rational& rhs){
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

// operator*的返回值前面加上const，是为了避免客户实现像下面这样的代码：
int main() {
    Rational a, b, c;
    // (a * b) = c; //加上const后，报错：没有与这些操作数匹配的 "=" 运算符 -- 操作数类型为:  const Rational = Rational

    int x, y, z;
    // x * y = z; //内置类型这样做也是不合法的，又因为“一个良好的用户自定义类型”的特征是它们避免无端地与内置类型不兼容（见条款18），
                 //所以我们确实应该在operator*的返回值前面加上const。
}