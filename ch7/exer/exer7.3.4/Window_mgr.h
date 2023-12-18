#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void Window_mgr::clear(ScreenIndex);
	Window_mgr &add_item(const Screen &item);
	Screen &get_item(ScreenIndex);
private:
	std::vector<Screen> screens{Screen(24, 80)};
};

Window_mgr &Window_mgr::add_item(const Screen &item)
{
	screens.push_back(item);
	return *this;
}
	
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}
Screen &get_item(ScreenIndex i)
{
	return &screens[i];
}
#endif 
