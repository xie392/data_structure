//
// Created by xie392 on 2023/5/20.
//
//#include "../seqstack.c"
#include <stdio.h>

/**
 * 将数字字符转换为相应的数
 * @param {char} c[]        字符串数组
 * @param {int} i           字符串数组下标
 * @return {double}
 */
double transformStr(char c[], int *i) {
    double x = 0.0;
    int k = 0;

    // 处理整数部分 0~9
    while (c[*i] >= '0' && c[*i] <= '9') {
        // 将字符转换为数字
        x = 10 * x + (c[*i] - '0');
        // 下标后移
        (*i)++;
    }

    // 处理小数部分
    if (c[*i] == '.') {
        (*i)++;
        // 处理小数部分 0~9
        while (c[*i] >= '0' && c[*i] <= '9') {
            x = 10 * x + (c[*i] - '0');
            (*i)++;
            k++;
        }
    }

    while (k != 0) {
        x /= 10.0;
        k--;
    }

    return x;
}

/**
 * 求一个后缀表达式的值
 * @param {char} c[]        字符串数组
 * @return double
 */
double EvalPost(char c[]) {
    double obst[100], x1, x2;
    int top = 0, i = 0;

    while (c[i] != '#') {
        if (c[i] >= '0' && c[i] <= '9') {
            // 把处理好的数据添加进数组
            obst[top] = transformStr(c, &i);
            top++;
        } else if (c[i] == ' ') {
            i++;
        } else if (c[i] == '+') {
            x2 = obst[--top];
            x1 = obst[--top];
            obst[top] = x1 + x2;
            top++;
            i++;
        } else if (c[i] == '-') {
            x2 = obst[--top];
            x1 = obst[--top];
            obst[top] = x1 - x2;
            top++;
            i++;
        } else if (c[i] == '*') {
            x2 = obst[--top];
            x1 = obst[--top];
            obst[top] = x1 * x2;
            top++;
            i++;
        } else if (c[i] == '/') {
            x2 = obst[--top];
            x1 = obst[--top];
            obst[top] = x1 / x2;
            top++;
            i++;
        }
    }

    return obst[0];
}

int main() {
    char c[100];
    printf("请输入后缀表达式：");
    //  允许输入空格
    scanf("%[^\n]", c);

    printf("结果为：%f", EvalPost(c));

    return 0;
}
