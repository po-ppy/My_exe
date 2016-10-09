// filename: funptGenArg.c
#include <stdio.h>
#include <stdlib.h>

// 为函数类型定义别名
typedef int (* fooType)(int, int);

// 声明结构体
struct aritmathic
{
    int a;
    int b;
    fooType add;
    fooType subtract;
    fooType multiply;
};

// 函数原型
int Add(int a, int b);
int Subtract(int a, int b);
int Multiply(int a, int b);

int main()
{
    // 定义结构体类型的变量
    struct aritmathic ar;
    // 结构体数据成员赋值
    ar.a = 4;
    ar.b = 5;
    // 结构体函数指针赋值
    ar.add = Add;
    ar.subtract = Subtract;
    ar.multiply = Multiply;

    // 通过函数指针调用函数，操作结构数据成员
    int a = ar.add(ar.a, ar.b);
    int b = ar.subtract(ar.a, ar.b);
    int c = ar.multiply(ar.a, ar.b);

    // 输出结果
    printf("%d\n%d\n%d", a, b, c);

    return 0;
}

// 加法
int Add(int a, int b)
{
    return (a + b);
}

// 减法
int Subtract(int a, int b)
{
    return (a - b);
}

// 乘法
int Multiply(int a, int b)
{
    return (a * b);
}
