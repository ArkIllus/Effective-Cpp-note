// 多重继承的确有正当用途。其中一个使用情况：
// 当一个类“public继承某个interface class”和“private继承某个协助实现的class”两个相结合的时候。


#include <string>
using namespace std;

// interface class
class Iperson{
public:
    virtual ~Iperson();
    virtual string name() const = 0;
    virtual string birthDate() const = 0; 
};

class DatabaseID {
    // ...
};

// 协助实现的class
class PersonInfo{
public:
    explicit PersonInfo(DatabaseID pid);
    virtual ~PersonInfo();
    virtual const char* theName() const;
    virtual const char* theBirthDate() const;
    virtual const char* valueDelimOpen() const;
    virtual const char* valueDelimClose() const;
};

// CPerson
class CPerson: public Iperson, private PersonInfo {
public:
    explicit CPerson(DatabaseID pid): PersonInfo(pid) {}
    virtual const char* theName() const{
        return PersonInfo::theName();
    }
    virtual const char* theBirthDate() const{
        return PersonInfo::theBirthDate();
    }
private:
    virtual const char* valueDelimOpen() const{
        return "";
    }
    virtual const char* valueDelimClose() const{
        return "";
    }
};

int main(){
}