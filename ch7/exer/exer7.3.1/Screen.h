#ifndef SCREEN_H_
#define SCREEN_H_
#include <string>

class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos w, pos h, char c = " "): 
		height(h), width(w), contents(h*w, c) {}
	char get() const {return contents[cursor]; }
	inline char get(pos w, pos h) const;
	Screen &move(pos r, pos c);
	// get/set函数
	void display() const;
	inline pos get_height() const { return height; }
	inline pos get_width() const { return width; }
	inline pos get_cursor() const { return cursor; }
	inline unsigned get_luminance() const { return luminance; }
	inline Screen &set_luminance(unsigned value) { luminance = value; return *this; }
	inline unsigned get_refresh() const { return refresh; }
	inline Screen &set_refresh(unsigned rf_rate) { refresh = rf_rate; return *this; }
	inline std::string get_brand() const { return brand; }
	inline std::string set_brand(std::string name) { brand = name; }
	inline Screen &set_contents(char); 
	inline Screen &set_contents(char, pos, pos);
	// void set_contents(char, pos, pos); 
	// 本来想做一个根据cursor的位置进行修改长、宽为pos类型乘积的区域，但是不知道cursor原本的坐标值
	// 否则需要定义两个属性来表示cursor，而不是一个cursor；
	void close_screen();

private:
	pos cursor = 0; 
	pos height = 0; // 一旦初始化，屏幕的宽高不能变
	pos width = 0;
	unsigned luminance = 200;
	unsigned refresh = 60;
	std::string brand = "BOE"; //京东方
	std::string contents;
};
// 同书上P246的set
inline Screen &Screen::set_contents(char label) 
{ 
	contents[cursor] = label; 
	return *this; 
}
Screen &Screen::set_contents(char label, pos l, pos w) 
{ 
	contents[l * width + w] = label; 
	return *this; 
}
void Screen::close_screen()
{
	for (pos i = 0; i < height; ++i) {
		for (pos j = 0;j < width; ++j)
			content[i * width + j] = "X";
}
void &Screen::display() const
{
	for (pos i = 0; i < height; ++i) {
		for (pos j = 0;j < width; ++j)
			std::cout << content[i * width + j];
		cout << endl;
	}
}
inline char Screen::get(pos r, pos c) const 
{
	pos rows = r * width;
	return contents[rows + c];
}
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
#endif
