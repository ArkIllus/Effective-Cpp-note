## Effective C++

#### 一、让自己习惯C++ (Accustoming Yourself to C++ )

1. 视C++ 为一个语言联邦 （View C++ as a federation of languages )

   * 四个次语言：C、Object-Oriented C++、Template C++、STL。

   * C++高效编程守则视状况而变化，取决于使用C++的哪一部分（哪个次语言）。

2. 尽量以const, enum, inline替换#defines（Prefer consts,enums, and inlines to #defines.)

   * 对于单纯的常量，最好以const对象或enums替换#define。

   * 对于形似函数的宏（macro），最好改用inline函数替换#define。

3. 尽可能使用const（Use const whenever possible.)

   - 将某些东西声明为const可以帮助编译器检查出错误用法。const可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
   - 编译器强制实施bitwise constness，但你编写程序时应该使用“概念上的常量性”（conceptual constness）。
   - 当const和非const版本有着实质等价的实现时，令non-const版本调用const版本可以避免代码重复。

4. 确定对象被使用前已先被初始化（Make sure that objects are initialized before they're used.)

   * 为内置型对象进行手工初始化，因为C++不保证初始化他们。

   * 构造函数最好使用成员初值列（member initialization list），而不要在构造函数本体内使用赋值操作（assignment）。初值列列出的成员变量，其排列次序应该和它们在class中的声明次序相同。

   * 为免除“跨文件编译的初始化次序问题”，应该以local static对象替换non-local static对象。

#### 二、构造/析构/赋值运算 (Constructors, Destructors, and Assignment Operators)

5. 了解C++ 那些自动生成和调用的函数（Know what functions C++ silently writes and calls.)
   - 编译器可以自动为class生成default构造函数、copy拷贝构造函数，copy assignment拷贝赋值操作符，以及析构函数。
6. 若不想使用编译器自动生成的函数，就该明确拒绝（Explicitly disallow the use of compiler-generated functions you do not want.)
   - 为驳回编译器自动（暗自）提供的机能（即默认自动生成函数），可将相应的成员函数声明为private并且不予实现。或者设置成delete的，或者private继承一个Uncopyable的base class。
7. 为多态基类声明virtual析构函数（Declare destructors virtual in polymorphic base classes.)
8. 别让异常逃离析构函数（Prevent exceptions from leaving destructors.)
9. 绝不在构造和析构过程中调用virtual函数（Never call virtual functions during construction or destruction.)
10. 令operator= 返回一个reference to *this （Have assignment operators return a reference to *this.）
11. 在operator= 中处理“自我赋值” （Handle assignment to self in operator=)
12. 复制对象时勿忘其每一个成分 （Copy all parts of an object)

#### 三、资源管理 (Resource Management)

13. 以对象管理资源 （Use objects to manage resources)
14. 在资源管理类中小心coping行为 （Think carefully about copying behavior in resource-managing classes)
15. 在资源管理类中提供对原始资源的访问（Provide access to raw resources in resource-managing classes)
16. 成对使用new和delete时要采取相同形式 （Use the same form in corresponding uses of new and delete)
17. 以独立语句将newed对象置入智能指针 （Store newed objects in smart pointers in standalone statements)

#### 四、设计与声明 (Designs and Declarations)

18. 让接口容易被正确使用，不易被误用 （Make interfaces easy to use correctly and hard to use incorrectly)
    - 好的接口很容易被正确使用，不容易被误用。你应该在你的所有接口总努力达成这些性质。
    - “促进正确使用”的办法包括接口的一致性，以及与内置类型的行为兼容。
    - “阻止误用”的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任。
    - shared_ptr支持定制删除器。这可防范dll问题，可被用来自动解除互斥锁（mutexes;见条款14）等。
19. 设计class犹如设计type （Treat class design as type design)
    * 略
20. 以pass-by-reference-to-const替换pass-by-value （Prefer pass-by-reference-to-const to pass-by-value)
    * 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题（slicing problem）。
    * 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当。
21. 必须返回对象时，别妄想返回其reference （Don't try to return a reference when you must return an object)
    * 绝不要返回pointer或reference指向一个local stack对象，或返回reference指向一个heap-allocated对象，或返回pointer或reference指向一个local static对象而有可能同时需要多个这样的对象。条款4已经为“在单线程环境中合理返回reference指向一个local static对象”提供了一份设计实例。
22. 将成员变量声明为private （Declare data members private)
23. 以non-member、non-friend替换member函数 （Prefer non-member non-friend functions to member functions)
24. 若所有参数皆需类型转换，请为此采用non-member函数 （Declare non-member functions when type conversions should apply to all parameters)
25. 考虑写出一个不抛异常的swap函数 （Consider support for a non-throwing swap)

#### 五、实现 (Implementations)

26. 尽可能延后变量定义式的出现时间 （Postpone variable definitions as long as possible)
27. 尽量不要进行强制类型转换 （Minimize casting)
28. 避免返回handles指向对象内部成分 （Avoid returning "handles" to object internals)
29. 为“异常安全”而努力是值得的 （Strive for exception-safe code)
30. 透彻了解inlining （Understand the ins and outs of inlining)
31. 将文件间的编译依存关系降至最低 （Minimize compilation dependencies between files)

#### 六、继承与面向对象设计 (Inheritance and Object-Oriented Design)

32. 确定你的public继承塑模出is-a关系 （Make sure public inheritance models "is-a.")

    - “public继承”意味is-a。适用于base classes身上的每一件事情一定也适用于derived classes身上，因为每一个derived class对象也是一个base class对象。
33. 避免遮掩继承而来的名称 （Avoid hiding inherited names)
34. 区分接口继承和实现继承 （Differentiate between inheritance of interface and inheritance of implementation)

    - 接口继承和实现继承不同，在public继承下，derived classes总是继承base class的接口。
    - pure virtual函数只具体指定接口继承。
    - 简朴的（非纯）impure virtual函数具体指定接口继承以及缺省实现继承。
    - non-virtual函数具体指定接口继承以及强制性的实现继承。
35. 考虑virtual函数以外的其他选择 （Consider alternatives to virtual functions)
36. 绝不重新定义继承而来的non-virtual函数 （Never redefine an inherited non-virtual function)

    * 绝对不要重新定义继承而来的non-virtual函数。
37. 绝不重新定义继承而来的缺省参数值 （Never redefine a function's inherited default parameter value)
38. 通过复合塑模出has-a或"根据某物实现出" （Model "has-a" or "is-implemented-in-terms-of" through composition)

    - 复合（composition）的意义和public继承完全不同。
    - 在应用域（application domain），复合意味着has-a（有一个），在实现域（implementation domain），复合意味着 is-implemented-in-terms-of（根据某物实现出）。
39. 明智而审慎地使用private继承 （Use private inheritance judiciously)

    * private 继承意味着is implemented in terms of（根据某物实现出）， 通常比复合（composition）的级别低，但是当derived class 需要访问protected base class 的成员，或者需要重新定义继承而来的virtual函数时，这么设计是合理的。

    * 和复合（composition）不同，private继承可以造成empty base最优化，这对致力于“对象尺寸最小化”的程序库开发者而言，可能很重要。
40. 明智而审慎地使用多重继承 （Use multiple inheritance judiciously)
    - 多重继承比单一继承复杂。它可能导致新的歧义性，以及对virtual继承的需要。
    - virtual继承会增加大小、速度、初始化（及赋值）复杂度等成本，如果virtual base classes不带任何数据，将是最具实用价值的情况
    - 多重继承的确有正当用途。其中一个使用情况：当一个类“public继承某个interface class”和“private继承某个协助实现的class”两个相结合的时候。

#### 七、模板与泛型编程 (Templates and Generic Programming)

41. 了解隐式接口和编译期多态 （Understand implicit interfaces and compile-time polymorphism)
42. 了解typename的双重意义 （Understand the two meanings of typename)
43. 学习处理模板化基类内的名称 （Know how to access names in templatized base classes)
44. 将与参数无关的代码抽离templates （Factor parameter-independent code out of templates)
45. 运用成员函数模板接受所有兼容类型 （Use member function templates to accept "all compatible types.")
46. 需要类型转换时请为模板定义非成员函数 （Define non-member functions inside templates when type conversions are desired)
47. 请使用traits classes表现类型信息 （Use traits classes for information about types)
48. 认识template元编程 （Be aware of template metaprogramming)

#### 八、定制new和delete (Customizing new and delete)

49. 了解new-handler的行为 （Understand the behavior of the new-handler)
50. 了解new和delete的合理替换时机 （Understand when it makes sense to replace new and delete)
51. 编写new和delete时需固守常规（Adhere to convention when writing new and delete)
52. 写了placement new也要写placement delete（Write placement delete if you write placement new)

#### 九、杂项讨论 (Miscellany)

53. 不要轻忽编译器的警告（Pay attention to compiler warnings)
54. 让自己熟悉包括TR1在内的标准程序库 （Familiarize yourself with the standard library, including TR1)
55. 让自己熟悉Boost （Familiarize yourself with Boost)