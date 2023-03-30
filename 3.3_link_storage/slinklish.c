#include "slinklist.h"

// ����һ���յĵ�����
node *init(){
	return NULL;
}

// ����������и����ڵ��ֵ
void display(node *head){
	node *p;
	p = head;
	if(!p) {
		printf("\n�������ǿյ�!");
	}
	else {
		printf("\n�������������ֵΪ:\n");
		while(p) {
			printf("%5d",p -> info);
			p = p -> next;
		}
	}
}

// �ڵ������в��ҵ� i ���ڵ�Ĵ�ŵ�ַ
node *find(node *head, int i) {
	int j = 1;
	node *p = head;

	if(i < 1) return NULL;

	while(p && i != j) {
		p = p -> next;
		j++;
	}

	return p;
}

// ���������
node *insert(node *head,datatype x,int i){
	node *p,*q;
	q = find(head,i);

	if(!q && i != 0) {
		printf("\n�Ҳ�����%d���ڵ㣬���ܲ���%d!",i,x);
	}
	else {
		p = (node*)malloc(sizeof(node));
		p -> info = x;
		if(i == 0) {
			p -> next = head;
			head = p;
		} 
		else {
			p -> next = q -> next;
			q -> next = p;
		}
	}
	return head;
}

// ������ɾ��
node *dele(node *head, datatype x) {
    node *pre = NULL, *p;

    if(!head) {
        printf("\n�������ǿյ�!");
        return head;
    }

    p = head;

    while(p && p -> info != x) {
        pre = p;
        p = p -> next;
    }

    if(p){
        if(pre) {
            head = head -> next;
        } else {
            pre -> next = p -> next;
        }
        free(p);
    }
    return head;
}
