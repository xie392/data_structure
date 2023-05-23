#include <stdio.h>

/**
 * 计算阶乘
 * @param n 非负整数
 * @return n的阶乘
*/
int fact(int n)
{
    return n == 0 ? 1 : n * fact(n - 1);
}

int main()
{
    printf("3! = %d\n", fact(3));
    return 0;
}