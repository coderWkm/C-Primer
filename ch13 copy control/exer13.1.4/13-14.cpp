#include <iostream>
class numbered {
public:
    numbered() {
        mysn = num++;
    }
    /*
    numbered(const numbered &value) { 
        this->num = value.num;
    }
    numbered& operator=(const numbered &value) {
        this.num = value.num;
        return *this;
    }
    */
    int mysn;
private:
    static int num;
};
int numbered::num = 0;
void f (numbered s) {std::cout << s.mysn << std::endl;}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c); 
    return 0;
}
