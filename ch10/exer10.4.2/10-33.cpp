#include <iostream>
#include <fstream>
#include <iterator>

int main()
{
    std::ifstream input("input.txt");
    std::ofstream odd_output("odd_output.txt"), even_output("even_output.txt");
    std::istream_iterator<int> in(input), eof;
    std::ostream_iterator<int> out_odd(odd_output, " "), out_even(even_output, "\n");
    while (in != eof) {
        if (*in % 2 != 0) 
            *out_odd++ = *in++;
        else
            *out_even++ = *in++;
    }
    
    return 0;
}
