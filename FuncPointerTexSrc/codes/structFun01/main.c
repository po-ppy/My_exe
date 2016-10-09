// filename: funptThisfArg.c
#include <stdio.h>
#include <stdlib.h>

// 为函数类型定义别名
typedef struct aritmathic* arPt;
typedef int (* fooType)(arPt);

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
int Add(struct aritmathic* ar);
int Subtract(struct aritmathic* ar);
int Multiply(struct aritmathic* ar);

int main()
{

    struct aritmathic ar;
    ar.a = 4;
    ar.b = 5;

    ar.add = Add;
    ar.subtract = Subtract;
    ar.multiply = Multiply;

    int a = ar.add(&ar);
    int b = ar.subtract(&ar);
    int c = ar.multiply(&ar);

    printf("%d\n%d\n%d", a, b, c);

    return 0;
}
// 加法
int Add(struct aritmathic* ar)
{
    return (ar->a + ar->b);
}
// 减法
int Subtract(struct aritmathic* ar)
{
    return (ar->a - ar->b);
}
// 乘法
int Multiply(struct aritmathic* ar)
{
    return (ar->a * ar->b);
}
