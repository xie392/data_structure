//
// Created by 26363 on 2023/5/18.
//
#include "sequlist.c"

int main(){
    SeqList list;

    // ��ʼ��˳���
    init(&list);

    // ��˳���������Ԫ��
    for(int i = 0; i < 10; i++){
        append(&list, i);
    }

    // ������Ϊ 5 ��λ�ò���Ԫ�� 100
    insert(&list, 5, 100);

    // ɾ������Ϊ 2 ��Ԫ��
    delete(&list, 2);

    // �޸�����Ϊ 3 ��Ԫ��
    update(&list, 3, 200);

    // ȡ������Ϊ 4 ��Ԫ��
    printf("����Ϊ 4 ��Ԫ��Ϊ��%d\n", get(&list, 4));

    // ��ӡ˳���ĸ���Ԫ��
    print(&list);

    return 0;
}