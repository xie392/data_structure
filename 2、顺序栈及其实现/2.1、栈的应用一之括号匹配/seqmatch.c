//
// Created by xie392 on 2023/5/20.
//

#include "../seqstack.c"

/**
 * ƥ��ɹ��󣬳�ջ������1
 * @param S
 * @param str
 * @return  1: ƥ��ɹ� 0: ƥ��ʧ��
 */
int IsInStack(SeqStack *S, char str) {
    if (!IsEmpty(S) && ReadTopStack(S) == str) {
        // ƥ�䵽�Ҵ����ţ�ջ��Ԫ��Ϊ������ţ���ջ
        PopStack(S);
        return 1;
    }
    return 0;
}


/**
* �жϱ��ʽ�е������Ƿ�ƥ��
 * @param {char} str[]
 * @return {int} 1: ƥ�䲻�ɹ� 0: ƥ��ɹ�
*/
int Match(char str[]) {
    int i = 0;
    char c;
    SeqStack stack;
    // ��ʼ��ջ
    InitStack(&stack);

    while (str[i] != '#') {
        // �����ַ���
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                // ƥ�䵽�����š��������š�������ţ���ջ
                PushStack(&stack, str[i]);
                break;
            case '}':
            case ']':
            case ')':
                // ƥ�䵽�����š��������š��Ҵ����ţ���ջ
                c = str[i] == '}' ? '{' : str[i] == ']' ? '[' : '(';

                if(!IsInStack(&stack,c )){
                    return  1;
                }
                break;
        }
        i++;
    }

    // ���ջΪ�վ�˵��ƥ��ɹ�
    return IsEmpty(&stack)  ? 0 : 1;
}

int main() {
    char str[] = "{[()]}#";
    printf("(1Ϊƥ��ʧ�ܣ�0Ϊƥ��ɹ�)ƥ������%d\n", Match(str));
    return 0;
}