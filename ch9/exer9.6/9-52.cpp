#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <cctype>

int main()
{
    std::string expr = "(2+((3 * 5) - (6/2)))";
    std::stack<char> stk;
    unsigned paren_num = 0;
    std::string str_in_paren;

    for (std::string::size_type i = 0; i != expr.size(); ++i) {
        stk.push(expr[i]);
        if (expr[i] == '(') 
            ++paren_num;
        else if (paren_num > 0 && expr[i] == ')') {
            stk.pop(); // 出右括号
            str_in_paren = "";
            while (stk.top() != '(') { // 括号内的字符串出栈，暂存
                str_in_paren.push_back(stk.top());
                stk.pop();
            }
            stk.pop(); // 出左括号
            for (int i = str_in_paren.size() - 1; i != -1; --i)
                stk.push(str_in_paren[i]);
            --paren_num;
        }
    }

    std::string res;
    while (!stk.empty()) {
        res.insert(res.begin(), stk.top());
        //std::cout << stk.top();
        stk.pop();
    }
    std::cout << res << std::endl;

    return 0;
}
