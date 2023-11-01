#ifndef SCREEN_H_
#define SCREEN_H_
#include <string>

class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos w, pos h, char c = ' '): 
		height(h), width(w), contents(h*w, c) {}
	
	char get() const { return contents[cursor]; }
	inline char get(pos w, pos h) const;
	Screen &move(pos r, pos c);
	Screen &display(std::ostream &os) 
			{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const
			{ do_display(os); return *this; }
	inline Screen &set(char); 
	inline Screen &set(char, pos, pos);

private:
	pos cursor = 0; 
	pos height = 0; // 一旦初始化，屏幕的宽高不能变
	pos width = 0;
	std::string contents;
private:
	void do_display(std::ostream &os) const { os << contents; }
};
inline Screen &Screen::set(char label) 
{ 
	contents[cursor] = label; 
	return *this; 
}
Screen &Screen::set(char label, pos l, pos w) 
{ 
	contents[l * width + w] = label; 
	return *this; 
}
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
#endif
