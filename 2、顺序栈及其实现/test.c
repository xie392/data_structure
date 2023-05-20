//
// Created by xie392 on 2023/5/20.
//
#include "seqstack.c"

int main(){
    SeqStack stack;

    // ��ʼ��ջ
    InitStack(&stack);

    // ���Ԫ�ص�ջ��
    for(int i = 0; i < 5; i++){
        PushStack(&stack, i);
    }

    // ��ӡ����Ԫ��
    printf("ջ������Ԫ��Ϊ");
    PrintStack(&stack);
    printf("\n");

    // ��ӡջ��Ԫ��
    printf("ջ��Ԫ��Ϊ��%d\n", ReadTopStack(&stack));

    // ɾ��ջ��Ԫ��
    printf("ɾ��Ԫ�ز���...\n");
    PopStack(&stack);

    // ��ӡ����Ԫ��
    printf("ɾ��Ԫ�غ�ջ������Ԫ��Ϊ");
    PrintStack(&stack);
    printf("\n");

    return 0;
}
