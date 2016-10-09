/********* main.c *********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "first.h"
int main( void )
{
    a_test_st *aTestSt;
    char aStr[] = "abcdefg";
    char *pStr = NULL;
    int aInt = 0;
    aTestSt = (a_test_st*)malloc(sizeof( a_test_st));//申请内存空间
    memset(aTestSt, 0, sizeof(a_test_st));//对aTestSt中所有元素地址初始化为0
    aTestSt->elem = 45;//为结构中变量赋值
    aTestSt->get_char = my_get_char;//为aTestSt中函数指针赋值
    aTestSt->get_int = my_get_int;//为aTestSt中函数指针赋值
    pStr = aTestSt->get_char( aStr);//调用aTestSt的函数
    printf("aStr = %s/n", aStr);
    printf("aStr = %s/n", pStr);
    aInt = aTestSt->get_int( aTestSt->elem);//调用aTestSt的函数
    printf("aInt = %d/n", aInt);
    free(aTestSt);//释放aTestSt所指向内存空间
    aTestSt = NULL;//置空
    return 0;
}
char *my_get_char(char *str)
{
    //将str前两个字符返回
    char *pstr = NULL;
    pstr = str;
    *pstr = *str;
    *(pstr + 1) = *(str + 1);
    *(pstr + 2) = '\0';

    return pstr;
}
int my_get_int(int in)
{
    return in + 2;
}
/********* main.c *********/
