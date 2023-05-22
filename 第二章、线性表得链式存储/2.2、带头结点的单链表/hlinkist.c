#include "hlinkist.h"

/**
 * ����һ���յĴ�ͷ���ĵ�����
 * @return
 */
LinkNode *init() {
    LinkNode *head = (LinkNode *) malloc(sizeof(LinkNode));
    head->next = NULL;
    return head;
}

/**
* �����ͷ���ĵ������и�������ֵ
 * @param {LinkNode} *head
 * @return
*/
void print(LinkNode *head) {
    LinkNode *p = head->next;
    if (p == NULL) {
        printf("����ʧ�ܣ�����Ϊ��\n");
    }
    // ��ͷ������һ����㿪ʼ����
    while (p != NULL) {
        printf("%5d ", p->info);
        p = p->next;
    }
}

/**
* �ڴ�ͷ���ĵ������в��ҵ� i ������ַ
 * @param {LinkNode} *head
 * @param {int} i
 * @return LinkNode
*/
LinkNode *find(LinkNode *head, int i) {
    int j = 1;
    LinkNode *p = head;

    if(i < 0) {
        printf("����ʧ�ܣ�%d ֵ�Ƿ�\n",i);
        return NULL;
    } else if (i == 0) {
        return head;
    }

    // ���������������ǣ���ô��ʼ��������
    while (p && i != j) {
        // ���������ң��������� 1
        p = p->next;
        j++;
    }

    return p;
}

/**
* �ڴ�ͷ���ĵ������е� i ���������һ��ֵΪ x ���½��
 * @param {LinkNode} *head
 * @param {int} i
 * @param {dataType} x
 * @return LinkNode
*/
LinkNode *insert(LinkNode *head, int i, dataType x) {
    LinkNode *p, *s;
    // ���ҵ� i �����ĵ�ַ
    p = find(head, i);

    if (p == NULL) {
        printf("����ʧ�ܣ��� %d ����㲻����\n", i);
        return NULL;
    }
    // Ϊ׼��������½�����ռ�
    s = (LinkNode *) malloc(sizeof(LinkNode));
    // Ϊ�½������ֵΪ x
    s->info = x;
    // ���½����뵽�� i �����֮��
    s->next = p->next;
    // ���� i ������ next ָ���½��
    p->next = s;
    return head;
}

/**
* ��ͷ���ĵ�������ɾ��һ��ֵΪ x ��ֵ
 * @param {LinkNode} *head
 * @param {dataType} x
 * @return LinkNode
*/
LinkNode *dele(LinkNode* head, dataType x) {
    LinkNode *pre = head, *q;
    // q �Ӵ�ͷ���ĵ�һ��ʵ�ʽ�㿪ʼ�� x �Ľ��
    q = head -> next;

    while (q && q -> info != x) {
        // pre ָ�� q
        pre = q;
        // q ָ����һ�����
        q = q -> next;
    }

    if(!q) {
        printf("ɾ��ʧ�ܣ�ֵΪ %d �Ľ�㲻����\n", x);
        return NULL;
    }

    // �� q ����������ɾ��
    pre -> next = q -> next;
    // �ͷ� q ���Ŀռ�
    free(q);

    return head;
}