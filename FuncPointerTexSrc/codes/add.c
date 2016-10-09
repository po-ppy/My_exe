#include <stdio.h>
typedef int (*FunHandle)(int, int);
struct Example
{
    int a;
    int b;
    FunHandle fun;
};

int add(int, int);

int main()
{
    struct Example ex;
    int r;
    ex.a = 1;
    ex.b = 2;
    ex.fun = add;
    r = ex.fun(ex.a, ex.b);
    printf("%d + %d = %d \n", ex.a, ex.b, r);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
