#ifndef FIRST_H_INCLUDED
#define FIRST_H_INCLUDED

// 声明函数原型
char *my_get_char(char *str);
int my_get_int(int in);

// 函数类型重命名
typedef char* (*type_get_char)(char *str);
typedef int (*type_get_int)(int in);

// 结构体定义
struct test_st
{
    int elem;
    type_get_char get_char;
    type_get_int get_int;
};

// 结构体定义重命名
typedef struct test_st a_test_st;

#endif // FIRST_H_INCLUDED
