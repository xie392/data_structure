#include "seqstack.h"


/**
 * ջ�ĳ�ʼ��
 * @param S
 * @return void
 */
void InitStack(SeqStack *S) {
    S->top = 0;
}

/**
* �ж�ջ�Ƿ�Ϊ��
 * @param S
 * @return 1: �� 0: �ǿ�
*/
int IsEmpty(SeqStack *S) {
    return S->top == 0;
}

/**
* ��ȡջ��Ԫ��
 * @param S
 * @return ջ��Ԫ��
*/
DataType ReadTopStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("ջ��\n");
        return 0;
    }
    return S->data[S->top - 1];
}

/**
* ջ�Ĳ������
 * @param S
 * @param x
 * @return void
*/
void PushStack(SeqStack *S, DataType x) {
    if (S->top == MAXSIZE) {
        printf("ջ��\n");
        exit(1);
    }
    S->data[S->top++] = x;
}

/**
* ջ��ɾ������
 * @param S
 * @return void
*/
void PopStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("ջ��\n");
        exit(1);
    }
    // Ϊʲô���� S -> data[S->top] = 0; ?
    // ��Ϊ�����ᵼ��ջ��Ԫ�ر����� 0 ��
    S->top--;
}

/**
* ��ӡջ��Ԫ��
 * @param S
 * @return void
*/
void PrintStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("ջ��\n");
        exit(1);
    }
    for (int i = 0; i < S->top; i++) {
        printf("%5d ", S->data[i]);
    }
}