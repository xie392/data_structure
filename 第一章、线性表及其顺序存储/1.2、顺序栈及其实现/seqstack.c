#include "seqstack.h"


/**
 * 栈的初始化
 * @param S
 * @return void
 */
void InitStack(SeqStack *S) {
    S->top = 0;
}

/**
* 判断栈是否为空
 * @param S
 * @return 1: 空 0: 非空
*/
int IsEmpty(SeqStack *S) {
    return S->top == 0;
}

/**
* 读取栈顶元素
 * @param S
 * @return 栈顶元素
*/
DataType ReadTopStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("栈空\n");
        return 0;
    }
    return S->data[S->top - 1];
}

/**
* 栈的插入操作
 * @param S
 * @param x
 * @return void
*/
void PushStack(SeqStack *S, DataType x) {
    if (S->top == MAXSIZE) {
        printf("栈满\n");
        exit(1);
    }
    S->data[S->top++] = x;
}

/**
* 栈的删除操作
 * @param S
 * @return void
*/
void PopStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("栈空\n");
        exit(1);
    }
    // 为什么不把 S -> data[S->top] = 0; ?
    // 因为这样会导致栈顶元素被覆盖 0 了
    S->top--;
}

/**
* 打印栈中元素
 * @param S
 * @return void
*/
void PrintStack(SeqStack *S) {
    if (IsEmpty(S)) {
        printf("栈空\n");
        exit(1);
    }
    for (int i = 0; i < S->top; i++) {
        printf("%5d ", S->data[i]);
    }
}