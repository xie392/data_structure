#include "hlinkist.c"

int main() {
    // ��ʼ��������
    LinkNode *head = init();

    // ����
    for(int i = 0; i <= 10; i++) {
        insert(head, i, i);
    }

    // ��ӡ
    printf("���н��ֵΪ��");
    print(head);
    printf("\n");

    // ?ɾ��
    for(int i = 0; i < 5; i++) {
        dele(head, i);
    }

    printf("���н��ֵΪ��");
    print(head);
    printf("\n");

    return 0;
}