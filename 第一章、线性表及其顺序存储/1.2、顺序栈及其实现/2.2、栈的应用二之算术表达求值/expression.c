#include <stdio.h>
#include <math.h>

/**
 * ��һ����׺���ʽ��ֵ
 * @param {char} c[]        �ַ�������
 * @return double
 */
double calc(const char c[]) {
    double obst[100], x1, x2;
    int top = 0, i = 0;
    char str[100][100];

    while (c[i] != '\0') {

        /**
         * k ÿ�ν�����Ϊ 0����Ҫ����str��ά����ĵڶ�ά�±�ÿ�ν������� 0 ��ʼ
         * flag ���ڱ���Ƿ����ѭ�������û�н���ѭ����˵�������������������Ҫ��ջ
         */
        int k = 0, flag = 0;

        while (c[i] != ' ' && c[i] != '\0') {
            // ƥ�䵽 0~9 �� "." ����ջ����������ѭ��
            if ((c[i] >= '0' && c[i] <= '9') || c[i] == '.') {
                str[top][k++] = c[i++];
                flag = 1;
            } else {
                break;
            }
        }

        // ��������Ѿ���ջ�ˣ��Ͱ���ջ���ַ���ת���� double ���ͣ���� obst
        if (flag) {
            // ��ÿ���ַ������һ��Ԫ�ظ�ֵΪ '\0'����ֹ atof() ����ת������
            str[top][i] = '\0';
            // atof() �������ڽ��ַ���ת���� double ���ͣ���ת�����ֵ��� obst
            obst[top] = atof(str[top]);
            // top �������´�ѭ���Ϳ��Դ�����һ���ַ���
            top++;
            // ���� flag����ֹ�´�ѭ������
            flag = 0;
        }
        i++;

        // ƥ�䵽������������ʹ�ջ��ȡ������Ԫ�أ�������������
        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
            // ȡ��ջ����������Ԫ�أ��� x1 �� x2 ����
            x2 = obst[--top];
            x1 = obst[--top];
            // ��������
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
    printf("�������׺���ʽ��");
    //  ��������ո�
    scanf("%[^\n]", c);

    printf("���Ϊ��%f", calc(c));

    return 0;
}
