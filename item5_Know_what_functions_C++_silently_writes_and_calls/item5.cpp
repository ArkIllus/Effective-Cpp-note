// 如果你打算在一个内含reference成员/const成员的class内支持赋值（assignment）操作，
// 你必须自己定义copy assignment操作符。编译器并不会为你自动生成一个。

// 解释：很简单，因为比如下面的 namedObject1 = namedObject2;
// 1.让引用改指不同对象是不行的。
// 2.修改引用所指的对象？那样会影响到所有持有[[指向[该引用所指的对象]的reference/pointer]]的所有对象。这看起来也不太好。

#include <string>

template<class T>
class NamedObject {
public:
    NamedObject(std::string& name, const T object): nameValue(name), object(objectValue){}
private:
    std::string& nameValue; //reference成员
    const T objectValue; //const成员
};

int main() {
    std::string str1("aaa");
    std::string str2("bbb");
    NamedObject<int> namedObject1(str1, 1);
    NamedObject<int> namedObject2(str2, 2);

    // namedObject1 = namedObject2; //错误 无法引用 函数 "NamedObject<T>::operator=(const NamedObject<int> &) [其中 T=int]" (已隐式声明) -- 它是已删除的函数
}
