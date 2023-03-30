#include "slinklist.h"

// 建立一个空的单链表
node *init(){
	return NULL;
}

// 输出单链表中各个节点的值
void display(node *head){
	node *p;
	p = head;
	if(!p) {
		printf("\n单链表是空的!");
	}
	else {
		printf("\n单链表各个结点的值为:\n");
		while(p) {
			printf("%5d",p -> info);
			p = p -> next;
		}
	}
}

// 在单链表中查找第 i 个节点的存放地址
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

// 单链表插入
node *insert(node *head,datatype x,int i){
	node *p,*q;
	q = find(head,i);

	if(!q && i != 0) {
		printf("\n找不到第%d个节点，不能插入%d!",i,x);
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

// 单链表删除
node *dele(node *head, datatype x) {
    node *pre = NULL, *p;

    if(!head) {
        printf("\n单链表是空的!");
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
