//结构体中的指针函数以及“结构体”的继承
#include <stdio.h>
#include <stdlib.h>

struct Fruit
{
    void (*output)(void);
    int i;
};

struct Apple
{
    struct Fruit n;
    void (*output)(void);
};

void output_base(void);
void output_driven(void);
void output_apple(void);

int main()
{
    struct Fruit *p;
    struct Apple *q;
    struct Fruit base;
    struct Apple driven;
    base.i = 0;
    base.output = output_base;
    driven.n.i = 1;
    driven.n.output = output_driven;
    driven.output = output_apple;
    p = &base;
    printf("base's i is %d\n", p->i);
    p->output();
    p = (struct Fruit *)&driven;
    printf("driven's i is %d\n", p->i);
    q = &driven;
    q->output();

    return 0;
}

void output_base(void)
{
    printf("this is the base\n");
}

void output_driven(void)
{
    printf("this is the driven\n");
}

void output_apple()
{
    printf("this is apple's output\n");
}
