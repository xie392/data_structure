#include <stdio.h>
#include <math.h>

/**
 * 求一个后缀表达式的值
 * @param {char} c[]        字符串数组
 * @return double
 */
double calc(const char c[]) {
    double obst[100], x1, x2;
    int top = 0, i = 0;
    char str[100][100];

    while (c[i] != '\0') {

        /**
         * k 每次进来都为 0，主要用于str二维数组的第二维下标每次进来都已 0 开始
         * flag 用于标记是否进入循环，如果没有进入循环，说明是四则运算符，不需要入栈
         */
        int k = 0, flag = 0;

        while (c[i] != ' ' && c[i] != '\0') {
            // 匹配到 0~9 或 "." 可入栈，否则跳出循环
            if ((c[i] >= '0' && c[i] <= '9') || c[i] == '.') {
                str[top][k++] = c[i++];
                flag = 1;
            } else {
                break;
            }
        }

        // 如果上面已经入栈了，就把入栈的字符串转换成 double 类型，存给 obst
        if (flag) {
            // 给每个字符串最后一个元素赋值为 '\0'，防止 atof() 函数转换错误
            str[top][i] = '\0';
            // atof() 函数用于将字符串转换成 double 类型，把转换后的值存给 obst
            obst[top] = atof(str[top]);
            // top 自增，下次循环就可以存入下一个字符串
            top++;
            // 重置 flag，防止下次循环进入
            flag = 0;
        }
        i++;

        // 匹配到四则运算符，就从栈中取出两个元素，进行四则运算
        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
            // 取出栈中最后的两个元素，用 x1 和 x2 接收
            x2 = obst[--top];
            x1 = obst[--top];
            // 四则运算
            if(c[i] == '+') {
                obst[top++] = x1 + x2;
            } else if (c[i] == '-') {
                obst[top++] = x1 - x2;
            } else if (c[i] == '*') {
                obst[top++] = x1 * x2;
            } else if (c[i] == '/') {
                obst[top++] = x1 / x2;
            }
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

    printf("结果为：%f", calc(c));

    return 0;
}
