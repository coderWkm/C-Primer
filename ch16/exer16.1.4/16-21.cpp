#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &out = std::cerr) : os(out) {}
    template <typename F> 
    void operator() (F *p) const 
    {
        std::cout << "deleting..." << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

int main()
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int(1);
    DebugDelete()(ip);
    
    return 0;
}
