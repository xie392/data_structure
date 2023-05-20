//
// Created by xie392 on 2023/5/20.
//
//#include "../seqstack.c"
#include <stdio.h>

/**
 * �������ַ�ת��Ϊ��Ӧ����
 * @param {char} c[]        �ַ�������
 * @param {int} i           �ַ��������±�
 * @return {double}
 */
double transformStr(char c[], int *i) {
    double x = 0.0;
    int k = 0;

    // ������������ 0~9
    while (c[*i] >= '0' && c[*i] <= '9') {
        // ���ַ�ת��Ϊ����
        x = 10 * x + (c[*i] - '0');
        // �±����
        (*i)++;
    }

    // ����С������
    if (c[*i] == '.') {
        (*i)++;
        // ����С������ 0~9
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
 * ��һ����׺���ʽ��ֵ
 * @param {char} c[]        �ַ�������
 * @return double
 */
double EvalPost(char c[]) {
    double obst[100], x1, x2;
    int top = 0, i = 0;

    while (c[i] != '#') {
        if (c[i] >= '0' && c[i] <= '9') {
            // �Ѵ���õ�������ӽ�����
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
    printf("�������׺���ʽ��");
    //  ��������ո�
    scanf("%[^\n]", c);

    printf("���Ϊ��%f", EvalPost(c));

    return 0;
}
