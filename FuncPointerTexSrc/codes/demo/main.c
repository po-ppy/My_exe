#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体定义
struct my_struct
{
    void* data;
    int (*compare_func)(const void*, const void*);
};

// 结构体变量与整型数据比较
int my_struct_compare_to_data(struct my_struct* m, const void* comparable)
{
    return m->compare_func(m->data, comparable);
}

// 创建结构体变量
struct my_struct* my_struct_create(void* initial_data,
                                   int (*compare_func)(const void*, const void*))
{
    struct my_struct* result = malloc((sizeof(struct my_struct)));
    result->data = initial_data;
    result->compare_func = compare_func;
    return result;
}

// 比较两个整型数
int int_compare(const void* a_pointer, const void* b_pointer)
{
    return *(int*)a_pointer - *(int*) b_pointer;
}

// 比较两个字符串
int string_compare(const void* a_pointer, const void* b_pointer)
{
    return strcmp(*(char**)a_pointer, *(char**)b_pointer);
}

// 测试
int main(int argc, const char* argv[])
{
    // 构造一个整型结构体
    int int_data = 42;
    struct my_struct* int_comparator =
            my_struct_create(&int_data, int_compare);

    // 构造一个字符串型结构体
    char* string_data = "Hello world";
    struct my_struct* string_comparator =
            my_struct_create(&string_data, string_compare);

    // 结构体变量与整变量比较
    int int_comparable = 42;
    if (my_struct_compare_to_data(int_comparator, &int_comparable) == 0)
    {
        printf("The two ints are equal.\n");
    }

    // 结构体变量字符串比较
    char* string_comparable = "Goodbye world";
    if (my_struct_compare_to_data(string_comparator,
                                  &string_comparable) > 0)
    {
        printf("The first string comes after the second.\n");
    }

    // 释放内存
    free(int_comparator);
    free(string_comparator);

    return 0;
}
