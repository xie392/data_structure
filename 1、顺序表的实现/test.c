//
// Created by 26363 on 2023/5/18.
//
#include "sequlist.c"

int main(){
    SeqList list;

    /**
     * ��ʼ��˳���
     */
    init(&list);

    /**
     * ��˳���������Ԫ��
     */
    for(int i = 0; i < 10; i++){
        append(&list, i);
    }

    /**
     * ��ӡ˳���ĸ���Ԫ��
     */
    insert(&list, 5, 100);

    /**
     * ɾ��˳����е�Ԫ��
     */
    delete(&list, 2);

    /**
     * �޸�˳����е�Ԫ��
     */
    update(&list, 3, 200);

    /**
     * ����˳����е�Ԫ��
     */
    printf("�±�Ϊ4��Ԫ�� %d\n", get(&list, 4));

    /**
     * ��ӡ˳���ĸ���Ԫ��
     */
    printf("All List:");
    print(&list);

    return 0;
}