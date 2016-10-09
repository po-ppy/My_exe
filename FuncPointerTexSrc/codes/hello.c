#include <stdio.h>
#include <stdlib.h>

struct a
{
    int (*func) (char *);
    void (*fun) (int);
};

int hello(char *name)
{
    printf("------%s\n", name);
    return 0;
}

void show(int data)
{
    printf("the give data is %d\n", data);
}

struct method
{
    void (*fun) (int);
};

void show1(int data)
{
    printf("this is show 1 %d\n", data * 10);
}
void show2(int data)
{
    printf("this is show 2 %d\n", data * 10);
}
void show3(int data)
{
    printf("this is show 3 %d\n", data * 10);
}

struct method method_arry[] =
{
    {show1},
    {show2},
    {show3},
};

int main()
{
    //在结构体定义中是函数，在下面中是成员，所以上面用;下面用,逗号
    struct a a1 =
    {
        hello,
        show,
    };

    a1.func("imlink");
    a1.fun(1111);
    int i;
    for(i = 0; i < 3; i++)
    {
        method_arry[i].fun(i);
    }
    //注意上面用method_arry[i].fun(i)调用，因为metod_arry中只有1个变量就是fun
    //再数组初始化时只是对于不同到数组成员赋予了不同到值。
    return 0;
}
