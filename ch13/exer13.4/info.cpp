#include "info.h"
#include <iostream>
#include <set>

//********************************************************
/*
    Message内部成员函数：
*/
void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMes(this);
}
void Message::add_to_Folders(const Message &mes)
{
    for (auto f: mes.folders)
        f->addMsg(this);
}
void Message::remove_from_Folders()
{
    for (auto f: folders)
        f->remMes(this);
}
Message::Message(const Message &copy):
    folders(copy.folders), contents(copy.contents)
{
    add_to_Folders(copy);
}
Message& Message::operator=(const Message &rhs)
{  
    remove_from_Folders();
    folders = rhs.folders;
    contents = rhs.contents;
    add_to_Folders(rhs);
    return *this;
}
Message::~Message()
{
    remove_from_Folders();
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f: lhs.folders)  //要声明友元
        f->remMes(&lhs);
    for (auto f: rhs.folders)
        f->remMes(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, lhs.folders);
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

void Folder::debug_print() {
    std::cerr << "Folder contains " << messages.size() << " messages" << std::endl;
    int ctr = 1;
    for (std::set<Message*>::iterator m = messages.begin();
         m != messages.end(); ++m) {
        std::cerr << "Message " << ctr++ << ":\n\t" << (*m)->contents << std::endl;
    }
}

/*
    Folder内部函数实现：
*/
void Folder::save(Message &m)
{
    messages.insert(&m);
    m.addFold(this);
}
void Folder::remove(Message &m)
{
    messages.erase(&m);
    m.remFold(this);
}

void Folder::add_to_Message(const Folder &fold)
{
    for (auto m: fold.messages)
        m->addFold(this);
}
void Folder::remove_from_Messages()
{
    for (auto m: messages)
        m->remFold(this);
}
Folder::Folder(const Folder &f) : 
    messages(f.messages)
{
    add_to_Message(f);
}
Folder::~Folder()
{
    remove_from_Messages();
}
Folder& 
    Folder::operator=(const Folder&)
{
    remove_from_Messages();

}
void Message::debug_print() {
    std::cerr << "Message:\n\t" << contents << std::endl;
    std::cerr << "Appears in " << folders.size() << " Folders" << std::endl;
}