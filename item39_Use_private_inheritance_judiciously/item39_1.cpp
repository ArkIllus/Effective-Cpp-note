class Person {};
class Student: private Person {}; //private继承
void eat(const Person& p){}
void study(const Student& s){}

int main() {
    Person p;
    Student s;
    eat(p);
    // eat(s); //错误：'Person' is an inaccessible base of 'Student'
            //不允许对不可访问的基类 "Person" 进行转换
            //解释：如果类之间的继承关系是private，编译器不会自动将一个派生类对象转换为其基类对象
}