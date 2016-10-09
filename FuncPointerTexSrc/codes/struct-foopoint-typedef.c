// filename: struct-foopoint-typedef.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 为函数类型定义别名
typedef void (* noParaFun)();
typedef void (* twoParaFun)(int, char *);

// 声明结构体
typedef struct student
{
    int id;
    char name[50];
    noParaFun pfInital;
    twoParaFun pfProcess;
    noParaFun pfDestroy;
} stu;

// 函数原型
void Initial();
void Process(int id, char *name);
void Destroy();

int main()
{
    stu *stu1;

    stu1 = (stu *)malloc(sizeof(stu));

    // 初始化结构体
    stu1->id = 1000;
    strcpy(stu1->name, "C++");
    // 为函数指针赋值
    stu1->pfInital = Initial;
    stu1->pfProcess = Process;
    stu1->pfDestroy = Destroy;

    printf("%d\t%s\n", stu1->id, stu1->name);

    // 通过函数指针调用函数
    stu1->pfInital();
    stu1->pfProcess(stu1->id, stu1->name);
    stu1->pfDestroy();

    free(stu1);

    return 0;
}

void Initial()
{
    printf("initialization...\n");
}

void Process(int id, char *name)
{
    printf("process...\n%d\t%s\n", id, name);
}

void Destroy()
{
    printf("destroy...\n");
}
