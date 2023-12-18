#include <iostream>
#include <string>
#include <vector>

/*
	一旦类定义在不同的头文件怎么办？
*/

using std::cin; using std::cout;
using std::endl;
using std::string; 
using std::vector;

class Screen;
class Window_mgr {
public:
	void clear();
};

class Screen {
friend void Window_mgr::clear();

public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos w, pos h, char c = ' '): 
		height(h), width(w), contents(h*w, c) {}
private:
	pos cursor = 0; 
	pos height = 0; 
	pos width = 0;
	std::string contents;
};
	
void Window_mgr::clear()
{
	Screen myScreen(10, 20, 'X');
    cout << "清理之前 myScreen 的内容是：" << endl;
    cout << myScreen.contents << endl;
    myScreen.contents = "";
    cout << "清理之后 myScreen 的内容是：" << endl;
    cout << myScreen.contents << endl;
}
int main() 
{
	Window_mgr w;
    w.clear();
	return 0;
}
