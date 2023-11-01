#include <iostream>
#include <string>

std::istream& read_file(std::istream& read);
int main()
{
    read_file(std::cin);
    return 0;
}

std::istream& read_file(std::istream& read)
{
    std::string buff;
    while (!read.eof()) {
        getline(read, buff);
        std::cout << buff << std::endl;
    }
    read.clear(read.rdstate() & ~read.eofbit);
    return read;
}
