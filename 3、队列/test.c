//
// Created by xie392 on 2023/5/21.
//

#include "sequence.c"

int main() {
    SeqQueue Q;

    // ��ʼ������
    InitQueue(&Q);

    // ���
    for (int i = 0; i < 10; i++) {
        EnQueue(&Q, i);
    }

    // ��ӡ����
    printf("�����е�Ԫ��Ϊ��");
    PrintQueue(Q);
    printf("\n");

    // ����
    for (int i = 0; i < 5; i++) {
        DeQueue(&Q);
    }

    // ��ӡ����
    printf("�����е�Ԫ��Ϊ��");
    PrintQueue(Q);
    printf("\n");
}