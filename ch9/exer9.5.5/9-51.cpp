#include <iostream>
#include <string>
#include <array>

class Date{
private:
    std::string separator{", /"};
    unsigned year = 9999;
    unsigned month = 99;
    unsigned day = 99;
public:
    Date() = default;
    Date(const std::string &date);
    std::array<std::string, 12> month_name{
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    std::array<std::string, 31> day_name{
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"
    };
    void print_info();
};

int main()
{
    Date date1("January 1, 1900");
    date1.print_info();

    Date date2("1/1/1900");
    date2.print_info();

    Date date3("Jan 1 1900");
    date3.print_info();

    Date date4 = Date();
    date4.print_info();
    
    return 0;
}

Date::Date(const std::string &date) 
{
    if (date.empty()) return ;
    std::string::size_type index = date.find_first_of(separator);
    if (index == std::string::npos) {
        std::cout << "输入字符串格式错误(用, / 或空格分隔年月日)" << std::endl;
        return ;
    }
    std::string::size_type mon_index = index; // mon_index 之前是月份
    std::string::size_type day_index = date.find_first_of(separator, mon_index + 1); // mon-day_index之间是日
    //std::string::size_type year_index = date.cend() - date.cbegin();
    std::string mon_str, day_str, year_str;
    // mon_str存储date中月份的字符串  
    /*
    for (std::string::size_type i = 0; i != mon_index; ++i)
        mon_str.push_back(date[i]);
    */
    mon_str.push_back(date[0]);
    mon_str.push_back(date[1]);
    mon_str.push_back(date[2]);
    for (std::array<std::string, 12>::size_type i = 0; i != month_name.size(); ++i)
    {
        if (mon_str.find(month_name[i]) != std::string::npos || 
            mon_str.find(day_name[i]) != std::string::npos) {
            this->month = i + 1;
            //std::cout << "月份录入成功：" << this->month << "月" << std::endl;
            break;
        } 
        else if (mon_str.find(day_name[i]) != std::string::npos) { // 输入的月份是数字字符串
            this->month = stoi(mon_str);  
            //std::cout << "月份录入成功：" << this->month << "月" << std::endl;
            break;
        }
    }
    if (this->month == 99) {
        std::cout << "月份录入失败！" << std::endl;
        return ;
    }
    // 第二个：day
    for (std::string::size_type i = mon_index + 1; i != day_index; ++i)
        day_str.push_back(date[i]);
    for (std::array<std::string, 31>::size_type i = 0; i != day_name.size(); ++i)
    {
        if (day_str.find(day_name[i]) != std::string::npos) {
            this->day = stoi(day_str);  // i + 1 也行
            break;
        }
    }
    if (this->day == 99) {
        std::cout << "日期录入失败！" << std::endl;
        return ;
    }
    // 第三个：year
    for (std::string::size_type i = day_index + 1; i != date.size(); ++i)
        year_str.push_back(date[i]);
    this->year = stoi(year_str);
}

void Date::print_info()
{
    std::cout << year << "年，" 
              << month << "月，" 
              << day << "日"
              << std::endl;
}