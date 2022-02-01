// 考虑这样一段代码
// class CTextBlock{
//     public:
//         CTextBlock(char* p): pText(p) {}
//         char& operator[](size_t position)const{
//             return pText[position];
//         }
//     private:
//         char *pText;
// };

// int main() {
//     const CTextBlock cctb("Hello"); 
//     char *pc = &cctb[0];
//     *pc = 'J';
// }
// 这种情况下不会报错，但是一方面声明的时候说了是const，一方面还修改了值。这种逻辑虽然有问题但是编译器并不会报错


#include <string>
using namespace std;

//mutable的用法：
class CTextBook {
public:
    size_t length() const;
private:
    char* pText;
    mutable size_t textLength; //最近一次计算的文本区块长度
    mutable bool lengthIsValid; //目前的长度是否有效
    //mutable成员变量即使在const成员函数内，也可以被修改。
};
size_t CTextBook::length() const { //const
    if (!lengthIsValid) {
        textLength = strlen(pText); //加mutable之后就不报错了
        lengthIsValid = true; //加mutable之后就不报错了
    }
    return textLength;
}