// 复合（composition）是类型之间的一种关系：当某种类型的对象内含其他类型的对象。

// 复合的意义：
// 1.has-a（有一个）
// 2.is-implemented-in-terms-of（根据某物实现出）

#include <string>

class Address {};
class PhoneNumber {};

// 1.has-a（有一个）
class Person {
private:
    std::string name;
    Address address;
    PhoneNumber voiceNumber;
    PhoneNumber faxNumber;
};