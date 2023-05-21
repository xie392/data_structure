//
// Created by xie392 on 2023/5/21.
// 单链表
//

#include "slinkist.h"

/**
 * 建立一个空的单链表
 * @param {LinkNode} **L
 * @return
 */
LinkNode *init() {
    return NULL;
}

/**
* 输出单链表中各个结点的值
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
* 在单链表中查找第 i 个结点的存放地址
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
* 单链表的插入操作
 * @param {LinkNode} *Head
 * @param {int} i
 * @param {dataType} x
 * @return
*/
LinkNode *insert(LinkNode *Head, int i, dataType x) {
    LinkNode *p, *q;
    // 查找第 i 个结点
    q = find(Head, i);

    if (!q && i != 0) {
        printf("找不到第 %d 个结点 \n", i);
        return NULL;
    }

    // 为新结点分配空间
    p = (LinkNode *) malloc(sizeof(LinkNode));
    // 将新结点插入到单链表中
    p->info = x;

    // 如果插入的节点作为单链表的第一个结点
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
* 单链表的删除操作
 * @param {LinkNode} *Head
 * @param {dataType} x
 * @return
*/
LinkNode *delete(LinkNode *Head, dataType x) {
    LinkNode *p, *q;

    if (!Head) {
        printf("删除失败：单链表为空 \n");
        return Head;
    }

    p = Head;

    while (p->info != x) {
        q = p;
        p = p->next;
    }

    if (!q) {
        Head = Head->next;
    } else {
        q->next = p->next;
    }

    free(p);

    return Head;
}