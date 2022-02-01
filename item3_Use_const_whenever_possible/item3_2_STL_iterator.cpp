#include <vector>
#include <iostream>
using namespace std;

int main() {
    // STL迭代器是以指针为根据塑膜出来的，所以迭代的作用就像个T*指针。

    // 模拟T* const（const pointer）
    vector<int> vec{0,1,2,3,4,5};
    const vector<int>::iterator it = vec.begin();
    *it = 10; //正确，改变it所指物
    // ++it; //错误，it是const
    for (auto& x: vec) {cout << x << " ";}
    cout << endl;

    // 模拟const T*（pointer-to-const）
    vector<int>::const_iterator cit = vec.begin();
    // *cit = 10; //错误，*cit是const
    ++cit; //正确，改变cit
    for (auto& x: vec) {cout << x << " ";}
}