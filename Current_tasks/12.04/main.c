#include <stdio.h>

int func(void)
{
    int a = 1;
    int *pA;

    pA = &a;
    printf("Sizeof(a) = %I64d, sizeof(*pA) = %I64d, a = %d, *pA = %d\n", sizeof(a), sizeof(*pA), a, *pA);
    printf("&a = %d, pA = %d\n", &a, pA);
    printf("&*a = %d, *&pA = %\n", &*pA, *&pA);
    return 0;
}

int func2(int a)
{
    return a * a;
}

void func3(int *a) {
    *a = *a**a;
}

int main()
{
    func();
    int num = 10;
    num = func2(num);
    printf("num = %d\n", num);
    num = 15;
    func3(&num);
    printf("num = %d\n", num);
    return 0;
}