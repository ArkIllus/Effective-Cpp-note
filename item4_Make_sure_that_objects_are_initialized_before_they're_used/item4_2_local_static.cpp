// 为免除“跨文件编译的初始化次序问题”，应该以local static对象替换non-local static对象。


// static对象：
// 寿命从被构造出来直到程序结束为止。
// 它们的析构函数会在main()结束时被自动调用。
// 包括global对象、定义于namespace作用域内的对象、在classes内、在函数内、以及在file作用域内被声明为static的对象。

// 函数内的static对象称为local static对象
// 函数外的static对象称为non-local static对象


// 编译单元（translation unit）：产出单一目标文件（single object file）的那些源码。
// 基本上它是单一源码文件加上其所含入的头文件（#include files）。


// 某个编译单元1内
class FileSystem { //来自你的程序库
public:
    // ...
    size_t numDisks() const; //众多成员函数之一
    // ...
};
extern FileSystem tfs; //预备给客户使用的对象 //the file system

// 某个编译单元2内
class Directory { //由程序库客户建立
public:
    Directory(/*params*/);
    // ...
};
Directory::Directory(/*params*/){
    // ...
    size_t disks = tfs.numDisks(); //使用tfs对象
    // ...
}
Directory tempDir(/*params*/); //为临时文件而做出的目录
// 问题：如何确定tfs会在tempDir之前先被初始化？

// C++对“定义于不同的编译单元内的non-local static对象”的初始化相对次序并无明确定义。