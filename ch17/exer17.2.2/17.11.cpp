#include <iostream>
#include <bitset>
/**
 * 17.11
 * 只需要在初始化对象时填充模板参数N即可
*/
template <unsigned N>
class Result {
public:
    Result() = default;
    void set_res(int, bool);
    size_t size() { return status.size(); }
    void print_res();
    int get_scores(const Result<N>&);
private:
    std::bitset<N> status;
};
int main()
{   
    // 17.12
    Result<32> res;
    res.set_res(5, true);
    res.print_res();

    // 17.13
    Result<10> real, result; // 10道题， real是真实解答，result是答案
    result.set_res(2, true);
    result.set_res(5, true);
    result.set_res(7, true);
    result.set_res(9, true);
    // 设置正确结果
    real.set_res(2, true); 
    real.set_res(4, true); 
    real.set_res(7, true); 
    real.set_res(9, true); 
    real.get_scores(result);

    return 0;
}

template <unsigned N>
void Result<N>::set_res(int i, bool res)
{
    if (i >= N)
        throw "输入的问题编号i不合法！";
    status[i] = res;
}
template <unsigned N>
void Result<N>::print_res()
{
    std::cout << "问题编号---答案：" << std::endl;
    for (int i = 0; i != status.size(); ++i)
        std::cout << i << "---" << status[i] << std::endl; 
}
template <unsigned N>
int Result<N>::get_scores(const Result<N> &res)
{
    std::cout << "满分：" << N * 10;
    int cnt = 0;
    for (int i = 0; i != N; ++i) {
        if (this->status[i] == res.status[i])
            ++cnt;
    }
    std::cout << "，得分：" << cnt * 10 << std::endl;
    return cnt * 10;
}