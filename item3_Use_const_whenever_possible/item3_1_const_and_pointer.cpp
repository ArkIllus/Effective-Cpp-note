//*左边的const：被指物是常量；*右边的const：指针自身是常量
char greeting[] = "Hello";
char* p1 = greeting;
const char* p2 = greeting; //const data
char* const p3 = greeting; //const pointer
const char* const p4 = greeting; //const pointer, const data

//下面2种写法是一样的（const都在*左边：被指物是常量）
class Widget{};
void f1(const Widget* pw);
void f1(Widget const * pw);