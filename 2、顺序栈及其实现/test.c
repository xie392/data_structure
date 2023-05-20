//
// Created by xie392 on 2023/5/20.
//
#include "seqstack.c"

int main(){
    SeqStack stack;

    // 初始化栈
    InitStack(&stack);

    // 添加元素到栈中
    for(int i = 0; i < 5; i++){
        PushStack(&stack, i);
    }

    // 打印所有元素
    printf("栈中所有元素为");
    PrintStack(&stack);
    printf("\n");

    // 打印栈顶元素
    printf("栈顶元素为：%d\n", ReadTopStack(&stack));

    // 删除栈顶元素
    printf("删除元素操作...\n");
    PopStack(&stack);

    // 打印所有元素
    printf("删除元素后栈中所有元素为");
    PrintStack(&stack);
    printf("\n");

    return 0;
}
