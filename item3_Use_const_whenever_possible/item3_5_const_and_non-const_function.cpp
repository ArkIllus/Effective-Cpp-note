// 让non-const函数调用其const版本，避免代码重复——即使这需要转型动作

class TextBook {
public:
    const char& operator[](int position) const{
        return text[position];
    }
    char& operator[](int position) {
        //两次cast
        return const_cast<char&>(
            static_cast<const TextBook&>(*this)[position] //对于【指针或引用】，static_cast 无法【丢掉】const或其他类型限定符；（但【加上】是可以的）
            );
        // 下面这么写好像也行
        // return const_cast<char&>(
        //     const_cast<const TextBook&>(*this)[position]
        //     );
    }
private:
    char* text;
};

int main() {

}