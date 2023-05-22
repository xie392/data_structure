
#include <stdio.h>

#include <stdio.h>
#include <string.h>

/**
 * �ж��Ƿ�Ϊ�����
 * @param {char} c
 * @return {int} 1: ������� 0: ���������
 */
int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * �ж���������ȼ�
 * @param {char} c
 * @return {int} ���ȼ�
 */
int Priority(char c) {
    switch (c) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

/**
* ��׺ת��׺
 * @param {char} infix[]    ��׺���ʽ
 * @param {char} postfix[]  ��׺���ʽ
 * @return
*/
void InfixToPostfix(const char infix[], char postfix[]) {
    char stack[100];
    int top = 0, i = 0, j = 0;

    while (infix[i] != '\0') {
        // ����������ֻ�"."ֱ��д���׺���ʽ
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // �������"("����ֱ����ջ
            stack[top++] = infix[i];
        } else if (infix[i] == ')') {
            // �������")"����ջ�е������д���׺���ʽ��ֱ������"("��"("��д���׺���ʽ
            while (stack[top - 1] != '(') {
                postfix[j++] = stack[--top];
            }
            // ��"("��ջ
            top--;
        } else if (IsOperator(infix[i])) {
            // ����������������д��һ���ո��������ֶ�λ��
            postfix[j++] = ' ';
            // ���������������ж�ջ������������ȼ������ջ����������ȼ����ڵ��ڵ�ǰ���������ջ�������д���׺���ʽ
            while (top > 0 && Priority(stack[top - 1]) >= Priority(infix[i])) {
                postfix[j++] = stack[--top];
            }
            // ����ǰ�������ջ
            stack[top++] = infix[i];
        }
        i++;
    }

    // ��ջ��ʣ��������д���׺���ʽ
    while (top > 0) {
        postfix[j++] = stack[--top];
    }

    // ���ַ���������д���׺���ʽ
    postfix[j] = '\0';


}


int main() {
    char infix[100];
    char postfix[100];
    printf("��������׺���ʽ��");
    scanf("%[^\n]", infix);
    InfixToPostfix(infix, postfix);
    printf("��׺���ʽΪ��%s\n", postfix);
    return 0;
}