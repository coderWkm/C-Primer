#include <iostream>
#include <fstream>
#include <vector>
#include <string>
void read_file(std::ifstream &is, 
                std::vector<std::string> &buff,
                const std::string filename);

int main()
{
    std::string file("..\\example\\file1.txt");
    std::vector<std::string> res;
    std::ifstream is;
    read_file(is, res, file);
    is.close();

    //打印
    for (int i = 0; i != res.size(); ++i)
        std::cout << res[i] << std::endl;
    return 0;
}

void read_file(std::ifstream &is, 
                std::vector<std::string> &buff,
                const std::string filename)
{
   is.open(filename);
   std::string tmp;
   if (is) {
        while (is >> tmp) {
            buff.push_back(tmp);
        }
   } 
   else {
    std::cerr << filename << "打开失败！";
    std::cout << std::endl;
   }
}
