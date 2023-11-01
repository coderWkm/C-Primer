#ifndef PERSON_H_
#define PERSON_H_

#include <string>

struct Person {
	std::string name;
	std::string address;

	Person() = default;
	Person(const std::string &iname, const std::string &addr):
			name(iname), address(addr) { }
	std::string get_name() const {return name; }
	std::string get_address() const {return address; }
};

std::ostream &print_info(std::ostream& output, const Person &person)
{
	output << person.name << " " << person.address;
	return output;
}

std::istream &read_info(std::istream& input, Person& person)
{
	input >> person.name >> person.address;
	return input;
}

#endif
