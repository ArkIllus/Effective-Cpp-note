// 复合（composition）是类型之间的一种关系：当某种类型的对象内含其他类型的对象。

// 复合的意义：
// 1.has-a（有一个）
// 2.is-implemented-in-terms-of（根据某物实现出）

#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

// 2.is-implemented-in-terms-of（根据某物实现出）
// 使用list实现set
template <class T>
class Set {
public:
    bool member(const T& item) const;
    void insert(const T& item);
    void remove(const T& item);
    std::size_t size() const;
private:
    std::list<T> rep;
};

template <typename T>
bool Set<T>::member(const T& item) const {
    return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template <typename T>
void Set<T>::insert(const T& item){
    if (!member(item)) rep.emplace_back(item);
}

template <typename T>
void Set<T>::remove(const T& item){
    typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), item); //typename
    if (it != rep.end()) rep.erase(it);
}

template <typename T>
std::size_t Set<T>::size() const {
    return rep.size();
}

int main() {
    Set<int> st;
    st.insert(1);
    st.insert(5);
    st.insert(10);
    st.remove(1);
    std::cout << "st.size() = " << st.size() << std::endl;
    std::cout << "st.member(1) = " << st.member(1) << std::endl;
    std::cout << "st.member(5) = " << st.member(5) << std::endl;
    std::cout << "st.member(6) = " << st.member(6) << std::endl;
    std::cout << "st.member(10) = " << st.member(10) << std::endl;
}