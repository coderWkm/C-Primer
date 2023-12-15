#ifndef DEBUG_DELETE_H
#define DEBUG_DELETE_H
#include <iostream>
#include <string>

class DebugDelete {
public:
    DebugDelete(std::string name, std::ostream &out = std::cerr) : os(out), type(name) 
    {}
    template <typename F> 
    void operator() (F *p) const 
    {
        std::cout << "deleting " << type << "..." << std::endl;
        delete p;
    }
private:
    std::ostream &os;
    std::string type;
};
#endif