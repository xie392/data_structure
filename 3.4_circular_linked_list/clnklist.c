#include "slinklist.h"

// ����һ���յ�ѭ��������
node *init(){
    return NULL;
}

// ��ȡѭ������������һ���ڵ�Ĵ洢��ַ
node *rear(node *head){
    // pָ��ѭ��������ĵ�һ���ڵ�
    node *p;
    // ���ѭ��������Ϊ�գ��򷵻�NULL
    if(!head){
        return NULL;
    }

    p = head;
    // �ӵ�һ���ڵ㿪ʼ��������������ֱ���������һ���ڵ�
    while(p->next != head){
        p = p->next;
    }
    return p;
}

// ���ѭ�����������и�������ֵ
void display(node *head){
    // pָ��ѭ��������ĵ�һ���ڵ�
    node *p;
    // ���ѭ��������Ϊ�գ��������ʾ��Ϣ
    if(!head){
        printf("�յ�");
    }
    else {
        printf("ѭ���������и�������ֵΪ��\n");
        printf("%5d ", head->info);
        p = head->next;

        // �ӵڶ����ڵ㿪ʼ��������������ֱ��������һ���ڵ�
        while (p != head){
            printf("%5d ", p->info);
            p = p->next;
        }
        printf("123");
    }
}

// ��ѭ���������в���ֵΪ x �Ľ��Ĵ洢��ַ
node *find(node *head,datatype x) {

    node *q;

    if(!head) {
        printf("ѭ��������Ϊ��!�޷��ҵ�ָ���ڵ�!\n");
        return NULL;
    }

    // pָ��ѭ��������ĵ�һ���ڵ�
    q = head;

    // �ӵ�һ���ڵ㿪ʼ��������������ֱ��������һ���ڵ�
    while (q -> next != head && q -> info != x) {
        q = q->next;

        // ���ѭ������������ֵΪ x �Ľ�㣬�򷵻ظý��Ĵ洢��ַ
        if (q->info == x) {
            return q;
        } else {
            printf("ѭ������������ֵΪ%d�Ľ��!\n", x);
            return NULL;
        }
    }
}

// ��ѭ��������ĵ� i �����֮ǰ����ֵΪ x ���½��
node *insert(node *head, datatype x, int i) {
     node *p,*q,*myrear;
     int j;

        // ����ռ�
     p = (node *)malloc(sizeof(node));
     p -> info = x;

    // ���ѭ��������Ϊ�գ����½����뵽ѭ����������
    if(i < 0) {
        printf("����λ�ò��Ϸ�!\n");
        free(p);
        return head;
    }

    if(i == 0 && !head) {
        p -> next = head;
        head = p;
        return head;
    }

    if(i == 0 && head) {
       myrear = rear(head);
       p -> next = head;
       myrear -> next = p;
        return head;
    }

    if(i>0 && !head) {
        printf("����λ�ò��Ϸ�!\n");
        free(p);
        return head;
    }

    if(i > 0 && head) {
        q = head;
        j = 1;

        // �ӵ�һ���ڵ㿪ʼ��������������ֱ�������� i - 1 ���ڵ�
        while(i != j && q -> next != head) {
            q = q -> next;
            j++;
        }

        if(i != j) {
            printf("����λ�ò��Ϸ�!\n");
            free(p);
            return head;
        }
        else {
            // ���½����뵽ѭ����������
            p -> next = q -> next;
            // ���½����뵽ѭ����������
            q -> next = p;
            return head;
        }
    }
}


// ɾ��ѭ���������е� i �����
node *dele(node *head,datatype x) {
   node *pre = NULL, *q;
   if(!head) {
       printf("ѭ��������Ϊ��!�޷�ɾ�����!\n");
       return head;
   }

   q = head;

    while (q -> next != head && q -> info != x) {
        pre = q;
        q = q -> next;
    }

    if(q -> info == x) {
        if(head -> next == head) {
            free(q);
            head = NULL;
        }
        else {
            pre = head -> next;
            while(pre -> next != q) {
                pre = pre -> next;
            }
            head = head -> next;
            pre -> next = head;
            free(q);
        }
        return head;
    }
    else {
        printf("ѭ������������ֵΪ%d�Ľ��!\n", x);
        return head;
    }
}
