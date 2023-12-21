#ifndef INFO_H_
#define INFO_H_
/*
    P460:13.4节拷贝控制示例
*/
#include <string>   // 存储message内容
#include <set>      // 存储指向Folder、Message指针集合

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string &str=""):
        contents(str) { }
    Message(const Message &);
    Message& operator=(const Message&);
    ~Message();
    // 从给定的Folder添加/删除Message
    void save(Folder &);
    void remove(Folder &);
    void debug_print();
private:
    std::string contents;
    std::set<Folder*> folders;  //包含此文本的folder
    // 两个执行公共操作的函数
    void add_to_Folders(const Message &);
    void remove_from_Folders();

    void addFold(Folder *f) { folders.insert(f); }
    void remFold(Folder *f) { folders.erase(f); }
};
void swap(Message&, Message&);

class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
public:
    Folder() {}
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    // Folder中对应的：将本Folder保存到传入的Message/从该Message删除
    void save(Message &);
    void remove(Message &);
    void debug_print();
private:
    std::set<Message*> messages; // 此Folder下的message
    // Folder类中对应的公共操作函数
    void add_to_Message(const Folder &);
    void remove_from_Messages();

    // 将该指向该Message的指针添加到本Folder的set中
    void addMsg(Message *p_m) { messages.insert(p_m); }    
    void remMes(Message *p_m) { messages.erase(p_m); }
};

#endif