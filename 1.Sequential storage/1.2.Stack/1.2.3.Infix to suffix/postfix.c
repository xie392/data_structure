
#include <stdio.h>
#include <string.h>

/**
 * 判断是否为运算符
 * @param {char} c
 * @return {int} 1: 是运算符 0: 不是运算符
 */
int IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * 判断运算符优先级
 * @param {char} c
 * @return {int} 优先级
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
* 中缀转后缀
 * @param {char} infix[]    中缀表达式
 * @param {char} postfix[]  后缀表达式
 * @return
*/
void InfixToPostfix(const char infix[], char postfix[]) {
    char stack[100];
    int top = 0, i = 0, j = 0;

    while (infix[i] != '\0') {
        // 如果遇到数字或"."直接写入后缀表达式
        if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // 如果遇到"("，则直接入栈
            stack[top++] = infix[i];
        } else if (infix[i] == ')') {
            // 如果遇到")"，则将栈中的运算符写入后缀表达式，直到遇到"("，"("不写入后缀表达式
            while (stack[top - 1] != '(') {
                postfix[j++] = stack[--top];
            }
            // 将"("出栈
            top--;
        } else if (IsOperator(infix[i])) {
            // 如果遇到运算符，先写入一个空格，用于区分多位数
            postfix[j++] = ' ';
            // 如果遇到运算符，判断栈顶运算符的优先级，如果栈顶运算符优先级大于等于当前运算符，则将栈顶运算符写入后缀表达式
            while (top > 0 && Priority(stack[top - 1]) >= Priority(infix[i])) {
                postfix[j++] = stack[--top];
            }
            // 将当前运算符入栈
            stack[top++] = infix[i];
        }
        i++;
    }

    // 将栈中剩余的运算符写入后缀表达式
    while (top > 0) {
        postfix[j++] = stack[--top];
    }

    // 将字符串结束符写入后缀表达式
    postfix[j] = '\0';


}


int main() {
    char infix[100];
    char postfix[100];
    printf("请输入中缀表达式：");
    scanf("%[^\n]", infix);
    InfixToPostfix(infix, postfix);
    printf("后缀表达式为：%s\n", postfix);
    return 0;
}