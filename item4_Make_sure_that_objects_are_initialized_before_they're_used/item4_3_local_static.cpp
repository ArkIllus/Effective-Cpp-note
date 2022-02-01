// 为免除“跨文件编译的初始化次序问题”，应该以local static对象替换non-local static对象。

// ...
// C++对“定义于不同的编译单元内的non-local static对象”的初始化相对次序并无明确定义。

// 解决办法：将每个non-local static对象搬到自己的专属函数内（并声明为static）。
// 这是【【【Singleton模式】】】的一个常见实现手法。
// C++保证，函数内的local static对象会在“该函数被调用期间”“首次遇上该对象的定义式”时被初始化。

// 某个编译单元1内
class FileSystem { //来自你的程序库
public:
    // ...
    size_t numDisks() const; //众多成员函数之一
    // ...
};
/*(还可以前加static?变成成员函数?=>单例模式)*/ 
FileSystem& tfs(){
    static FileSystem fs;
    return fs;
} //预备给客户使用的对象 //the file system

// 某个编译单元2内
class Directory { //由程序库客户建立
public:
    Directory(/*params*/);
    // ...
};
Directory::Directory(/*params*/){
    // ...
    size_t disks = tfs().numDisks(); //使用tfs对象
    // ...
}
/*(还可以前加static?变成成员函数?=>单例模式)*/ 
Directory& tempDir(/*params*/) {
    static Directory td;
    return td;
}//为临时文件而做出的目录