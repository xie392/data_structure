#include "../slinkist.h"

/**
 * 建立一个空的带头结点的单链表
 * @return
 */
LinkNode *init() {
    LinkNode *head = (LinkNode *) malloc(sizeof(LinkNode));
    head->next = NULL;
    return head;
}

/**
* 输出带头结点的单链表中各个结点的值
 * @param {LinkNode} *head
 * @return
*/
void print(LinkNode *head) {
    LinkNode *p = head->next;
    if (p == NULL) {
        printf("遍历失败：链表为空\n");
    }
    // 从头结点的下一个结点开始遍历
    while (p != NULL) {
        printf("%5d ", p->info);
        p = p->next;
    }
}

/**
* 在带头结点的单链表中查找第 i 个结点地址
 * @param {LinkNode} *head
 * @param {int} i
 * @return LinkNode
*/
LinkNode *find(LinkNode *head, int i) {
    int j = 1;
    LinkNode *p = head;

    if(i < 0) {
        printf("查找失败：%d 值非法\n",i);
        return NULL;
    } else if (i == 0) {
        return head;
    }

    // 如果以上情况都不是，那么开始遍历查找
    while (p && i != j) {
        // 继续向后查找，计数器加 1
        p = p->next;
        j++;
    }

    return p;
}

/**
* 在带头结点的单链表中第 i 个结点后插入一个值为 x 的新结点
 * @param {LinkNode} *head
 * @param {int} i
 * @param {dataType} x
 * @return LinkNode
*/
LinkNode *insert(LinkNode *head, int i, dataType x) {
    LinkNode *p, *s;
    // 查找第 i 个结点的地址
    p = find(head, i);

    if (p == NULL) {
        printf("插入失败：第 %d 个结点不存在\n", i);
        return NULL;
    }
    // 为准备插入的新结点分配空间
    s = (LinkNode *) malloc(sizeof(LinkNode));
    // 为新结点设置值为 x
    s->info = x;
    // 将新结点插入到第 i 个结点之后
    s->next = p->next;
    // 将第 i 个结点的 next 指向新结点
    p->next = s;
    return head;
}

/**
* 带头结点的单链表中删除一个值为 x 的值
 * @param {LinkNode} *head
 * @param {dataType} x
 * @return LinkNode
*/
LinkNode *dele(LinkNode* head, dataType x) {
    LinkNode *pre = head, *q;
    // q 从带头结点的第一个实际结点开始找 x 的结点
    q = head -> next;

    while (q && q -> info != x) {
        // pre 指向 q
        pre = q;
        // q 指向下一个结点
        q = q -> next;
    }

    if(!q) {
        printf("删除失败：值为 %d 的结点不存在\n", x);
        return NULL;
    }

    // 将 q 结点从链表中删除
    pre -> next = q -> next;
    // 释放 q 结点的空间
    free(q);

    return head;
}