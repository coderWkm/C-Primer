#include <iostream>
#include <sstream>
#include <string>

std::istream& read_file(std::istream& read);

int main()
{
    std::ostringstream write_str;
    write_str << "aaaa bbbb cccc";
    std::istringstream read(write_str.str());
    read_file(read);
    return 0;
}

std::istream &read_file(std::istream &read)
{
    std::string buff;
    while (!read.eof()) {
        read >> buff;
        std::cout << buff << std::endl;
    }
    read.clear(read.rdstate() & ~read.eofbit);
    return read;
}