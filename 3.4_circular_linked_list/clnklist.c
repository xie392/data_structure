#include "slinklist.h"

// 建立一个空的循环单链表
node *init(){
    return NULL;
}

// 获取循环单链表的最后一个节点的存储地址
node *rear(node *head){
    // p指向循环单链表的第一个节点
    node *p;
    // 如果循环单链表为空，则返回NULL
    if(!head){
        return NULL;
    }

    p = head;
    // 从第一个节点开始，依次向后遍历，直到遇到最后一个节点
    while(p->next != head){
        p = p->next;
    }
    return p;
}

// 输出循环单链表中中各个结点的值
void display(node *head){
    // p指向循环单链表的第一个节点
    node *p;
    // 如果循环单链表为空，则输出提示信息
    if(!head){
        printf("空的");
    }
    else {
        printf("循环单链表中各个结点的值为：\n");
        printf("%5d ", head->info);
        p = head->next;

        // 从第二个节点开始，依次向后遍历，直到遇到第一个节点
        while (p != head){
            printf("%5d ", p->info);
            p = p->next;
        }
        printf("123");
    }
}

// 在循环单链表中查找值为 x 的结点的存储地址
node *find(node *head,datatype x) {

    node *q;

    if(!head) {
        printf("循环单链表为空!无法找到指定节点!\n");
        return NULL;
    }

    // p指向循环单链表的第一个节点
    q = head;

    // 从第一个节点开始，依次向后遍历，直到遇到第一个节点
    while (q -> next != head && q -> info != x) {
        q = q->next;

        // 如果循环单链表中有值为 x 的结点，则返回该结点的存储地址
        if (q->info == x) {
            return q;
        } else {
            printf("循环单链表中无值为%d的结点!\n", x);
            return NULL;
        }
    }
}

// 在循环单链表的第 i 个结点之前插入值为 x 的新结点
node *insert(node *head, datatype x, int i) {
     node *p,*q,*myrear;
     int j;

        // 分配空间
     p = (node *)malloc(sizeof(node));
     p -> info = x;

    // 如果循环单链表为空，则将新结点插入到循环单链表中
    if(i < 0) {
        printf("插入位置不合法!\n");
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
        printf("插入位置不合法!\n");
        free(p);
        return head;
    }

    if(i > 0 && head) {
        q = head;
        j = 1;

        // 从第一个节点开始，依次向后遍历，直到遇到第 i - 1 个节点
        while(i != j && q -> next != head) {
            q = q -> next;
            j++;
        }

        if(i != j) {
            printf("插入位置不合法!\n");
            free(p);
            return head;
        }
        else {
            // 将新结点插入到循环单链表中
            p -> next = q -> next;
            // 将新结点插入到循环单链表中
            q -> next = p;
            return head;
        }
    }
}


// 删除循环单链表中第 i 个结点
node *dele(node *head,datatype x) {
   node *pre = NULL, *q;
   if(!head) {
       printf("循环单链表为空!无法删除结点!\n");
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
        printf("循环单链表中无值为%d的结点!\n", x);
        return head;
    }
}
