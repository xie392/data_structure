#include "slinkist.h"
/**
 * ����һ���յĵ�����
 * @param {LinkNode} **L
 * @return
 */
LinkNode *init() {
    return NULL;
}

/**
* ����������и�������ֵ
 * @param {LinkNode} *Head
 * @return
*/
void print(LinkNode *Head) {
    LinkNode *p = Head;
    if (!p) {
        printf("NULL");
        return;
    }
    while (p) {
        printf("%5d ", p->info);
        p = p->next;
    }
}

/**
* �ڵ������в��ҵ� i �����Ĵ�ŵ�ַ
 * @param {LinkNode} *Head
 * @param {int} i
 * @return LinkNode
*/
LinkNode *find(LinkNode *Head, int i) {
    LinkNode *p = Head;
    int j = 1;

    if (i < 1) return NULL;

    while (p && i != j) {
        p = p->next;
        j++;
    }

    return p;
}

/**
* ������Ĳ������
 * @param {LinkNode} *Head
 * @param {int} i
 * @param {dataType} x
 * @return
*/
LinkNode *insert(LinkNode *Head, int i, dataType x) {
    LinkNode *p, *q;
    // ���ҵ� i �����
    q = find(Head, i);

    if (!q && i != 0) {
        printf("�Ҳ����� %d ����� \n", i);
        return NULL;
    }

    // Ϊ�½�����ռ�
    p = (LinkNode *) malloc(sizeof(LinkNode));
    // ���½����뵽��������
    p->info = x;

    // �������Ľڵ���Ϊ������ĵ�һ�����
    if (i == 0) {
        p->next = Head;
        Head = p;
    } else {
        p->next = q->next;
        q->next = p;
    }

    return Head;
}

/**
* �������ɾ������
 * @param {LinkNode} *Head
 * @param {dataType} x
 * @return
*/
LinkNode *delete(LinkNode *Head, dataType x) {
    LinkNode *p , *pre = NULL;

    if (!Head) {
        printf("ɾ��ʧ�ܣ�������Ϊ�� \n");
        return Head;
    }

    p = Head;

    // ����ֵΪ x �Ľ��
    while (p->info != x) {
        // ���û���ҵ����ͼ�����
        pre = p;
        p = p->next;
    }

    // ��������ѭ��������p Ϊ NULL��˵��û���ҵ�ֵΪ x �Ľ�㣬��ôҪɾ������ͷ���
    if(!pre) {
        Head = Head -> next;
    } else {
        pre -> next = p -> next;
    }

    free(p);

    return Head;
}