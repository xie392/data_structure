#include "slinkist.c"


int main(){
    LinkNode *Head;

    // ��ʼ��������
    Head = init();

    for (int i = 0; i <= 10; i++) {
        // ���뵽������ı�ͷ
        Head = insert(Head, i, i);
    }

    // ���������
    printf("�������и�������ֵΪ��");
    print(Head);
    printf("\n");

    // ɾ��
    for(int i = 0; i < 5; i++) {
        Head = delete(Head, i);
    }

    // ���������
    printf("�������и�������ֵΪ��");
    print(Head);
    printf("\n");

}