#include "slinklish.c"

int main(){
	node *p;
	// �����յĵ�����
	p = init();

    // ����Ԫ��
    p = insert(p, 0, 0);
    p = insert(p, 1, 1);
    p = insert(p, 2, 2);
    p = insert(p, 3, 3);


    printf("���뵥����ɹ�!\n");

    // ���������
    display(p);

    // ɾ��
    dele(p, 2);

    printf("\nɾ��������ɹ�!\n");

	return 0;
}
