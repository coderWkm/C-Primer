#include <iostream>
#include <string>
/*
    18-19
*/
class Employee{
public:
    Employee() { id_card = num++; }
    Employee(const std::string &in_name) : name(in_name) { id_card = num++; }
    Employee(const Employee &);
    int get_id() { return this->id_card; }
    std::string get_name() { return this->name; }
private:
    static int num;
    std::string name;
    int id_card;
};

Employee::Employee(const Employee &new_member):name(new_member.name), id_card(num++) {} 

int Employee::num = 0;

int main()
{
    Employee num1("aaa");
    std::cout << num1.get_id() << ", " << num1.get_name() << std::endl;
    Employee num2(num1);
    std::cout << num2.get_id() << ", " << num2.get_name() << std::endl;
    
    return 0;
}
