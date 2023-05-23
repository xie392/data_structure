#include <stdio.h>

/**
 * 计算斐波那契数列
 * @param n 非负整数
 * @return 斐波那契数列第n项
 * @note 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * @note 0是第0项，1是第1项
 */
int fibona(int n)
{
    return n < 2 ? 1 : fibona(n - 1) + fibona(n - 2);
}


int main() {
    printf("fibona(5) = %d\n", fibona(5));
    return 0;
}