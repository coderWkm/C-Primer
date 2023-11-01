#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl;
using std::string; using std::vector;
using std::istream; using std::ostream;

struct Person {
	string name;
	string address;

	string get_name() const {return name; }
	string get_address() const {return address; }
};

istream &read_info(istream&, Person&);
ostream &print_info(ostream&, const Person&);

int main() 
{
	Person p;
	cout << "请输入你的姓名、家庭住址：";
	read_info(cin, p);
	cout << "你的信息：";
	print_info(cout, p) << endl;
	return 0;
}

ostream &print_info(ostream& output, const Person &person)
{
	output << person.name << " " << person.address;
	return output;
}

istream &read_info(istream& input, Person& person)
{
	input >> person.name >> person.address;
	return input;
}
