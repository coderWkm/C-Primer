#include <iostream>
#include <memory>
int main()
{
    typedef std::unique_ptr<int> IntP;
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    // IntP p0(ix);
    //编译错误提示：提供的参数ix不匹配unique_ptr的构造函数参数列表

    //以下均没有编译错误提示：
    IntP p1(pi);
    std::cout << "p1->" << *p1 << std::endl;
    // 错误原因：超出p1的作用域，p1会被销毁，delete会被调用，但是p1所指的空间不是new来的

    IntP p2(pi2);
    std::cout << "p2->" << *p2 << std::endl;
    // 导致pi2悬空

    IntP p3(&ix);
    std::cout << "p3->" << *p3 << std::endl;
    // 同p1

    IntP p4(new int(2048));
    std::cout << "p4->" << *p4 << std::endl;
    // 合法用法！
    
    IntP p5(p2.get());
    std::cout << "p5->" << *p5 << std::endl;
    // 退出p2和p5的作用域时，操作系统对这两个指针指向的同一位置delete了两次

    /*
    有运行时错误：
	static_assert(sizeof(_Tp)>0,
		      "can't delete pointer to incomplete type");
	delete __ptr;
    */ 
    return 0;
}
