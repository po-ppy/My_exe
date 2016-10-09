// filename: struct-foopoint.c
#include <stdio.h>
struct DEMO
{
    int x, y;
    int (*pf)(int, int); //函数指针
};

// 函数原型，注意都是int ()(int x, int y)类型的函数
int multi(int x, int y);
int add(int x, int y);

int main()
{
    struct DEMO demo;
    demo.pf = add; //结构体函数指针赋值
    printf("pf(3, 4)=%d\n", demo.pf(3, 4));

    demo.pf = multi;
    printf("pf(3, 4)=%d\n", demo.pf(3, 4));

    return 0;
}

int multi(int x, int y)
{
    return x * y;
}

int add(int x, int y)
{
    return x + y;
}
