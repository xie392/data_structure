//
// Created by xie392 on 2023/5/20.
//

#include "../seqstack.c"

/**
 * 匹配成功后，出栈，返回1
 * @param S
 * @param str
 * @return  1: 匹配成功 0: 匹配失败
 */
int IsInStack(SeqStack *S, char str) {
    if (!IsEmpty(S) && ReadTopStack(S) == str) {
        // 匹配到右大括号，栈顶元素为左大括号，出栈
        PopStack(S);
        return 1;
    }
    return 0;
}


/**
* 判断表达式中的括号是否匹配
 * @param {char} str[]
 * @return {int} 1: 匹配不成功 0: 匹配成功
*/
int Match(char str[]) {
    int i = 0;
    char c;
    SeqStack stack;
    // 初始化栈
    InitStack(&stack);

    while (str[i] != '#') {
        // 遍历字符串
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                // 匹配到左括号、左中括号、左大括号，入栈
                PushStack(&stack, str[i]);
                break;
            case '}':
            case ']':
            case ')':
                // 匹配到右括号、右中括号、右大括号，出栈
                c = str[i] == '}' ? '{' : str[i] == ']' ? '[' : '(';

                if(!IsInStack(&stack,c )){
                    return  1;
                }
                break;
        }
        i++;
    }

    // 如果栈为空就说明匹配成功
    return IsEmpty(&stack)  ? 0 : 1;
}

int main() {
    char str[] = "{[()]}#";
    printf("(1为匹配失败，0为匹配成功)匹配结果：%d\n", Match(str));
    return 0;
}