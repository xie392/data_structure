//
// Created by xie392 on 2023/5/21.
//

#include "slinkist.c"

int main(){
    LinkNode *Head, *p;

    // ��ʼ��������
    Head = init();

    for (int i = 1; i <= 10; i++) {
        // ���뵽������ı�ͷ
        Head = insert(Head, i + 1, i);
    }

    // ���������
    printf("�������и�������ֵΪ��");
    print(Head);
    printf("\n");

    // ɾ��
    for(int i = 0; i < 5; i++) {
        Head = delete(Head, 1);
    }

    // ���������
    printf("�������и�������ֵΪ��");
    print(Head);
    printf("\n");


}

