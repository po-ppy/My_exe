// filename: cmpThisInt.c
#include <stdio.h>
#include <stdlib.h>

// 结构体定义
struct int_struct
{
    int data;
    // 函数指针
    int (*compare_func)(const int, const int);
};

// 声明函数原型
// 实现结构体变量与整型数据比较的函数
int cmp_to_data(struct int_struct* m, int comparable);
// 创建结构体变量(注意函数指针作为形参)
struct int_struct* create_struct(int initial_data, int (*compare_func)(int, int));
// 比较两个整型数的函数
int int_compare(const int a, const int b);

// 测试
int main(int argc, const char* argv[])
{
    // 构造一个整型结构体
    int int_data = 42;
    // 用一个整型数和比较两个整型数的函数为实参
    struct int_struct* int_comparator = create_struct(int_data, int_compare);

    // 结构体变量与整变量比较
    int int_comparable = 42;
    if (cmp_to_data(int_comparator, int_comparable) == 0)
    {
        printf("The two ints are equal.\n");
    }

    // 释放内存
    free(int_comparator);

    return 0;
}

// 实现结构体变量与整型数据比较的函数
int cmp_to_data(struct int_struct* m, int comparable)
{
    return m->compare_func(m->data, comparable);
}

// 创建结构体变量(注意函数指针作为形参)
struct int_struct* create_struct(int initial_data,
                                 int (*compare_func)(int, int))
{
    // 分配内存空间
    struct int_struct* result = malloc((sizeof(struct int_struct)));
    // 给数据成员赋值
    result->data = initial_data;
    // 结函数指针赋值
    result->compare_func = compare_func;
    return result;
}

// 比较两个整型数的函数
int int_compare(const int a, const int b)
{
    return a - b;
}

