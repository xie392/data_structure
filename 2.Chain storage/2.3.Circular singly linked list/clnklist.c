#include "../slinkist.h"

/**
 * 建立一个空的循环单链表
 * @return LinkNode
 */
LinkNode *init()
{
    return NULL;
}

/**
 * 获得循环单链表的最后一个结点的存储地址
 * @param {LinlNode} head
 * @return LinkNode
 */
LinkNode *rear(LinkNode *head)
{
    LinkNode *p = head;

    if (!p)
    {
        printf("循环单链表为空\n");
        return NULL;
    }

    // 开始遍历，没有到达最后一个结点，继续向后
    while (p->next != head)
    {
        p = p->next;
    }
    return p;
}

/**
 * 输出循环单链表中各个结点的值
 * @param {LinkNode} head
 * @return void
 */
void print(LinkNode *head)
{
    LinkNode *p;

    if (!head)
        printf("循环单链表是空的！\n");
    else
    {
        p = head;
        // 输出非空表中第一个结点的值
        printf("%d ", p->info);
        // p 指向第一个结点的下一个结点
        p = head->next;

        while (p != head)
        {
            printf("%5d ", p->info);
            p = p->next;
        }
    }
}

/**
 * 循环单链表中查找值为 x 的结点的存储地址
 * @param {LinkNode} head
 * @param {dataType} x
 * @return LinkNode
 */
LinkNode *find(LinkNode *head, dataType x)
{
    LinkNode *p = head;

    if (!p)
    {
        printf("循环单链表为空\n");
        return NULL;
    }

    // 开始遍历，没有到达最后一个结点，继续向后
    while (p->next != head && p->info != x)
    {
        p = p->next;
    }

    if (p->info == x)
    {
        return p;
    }

    return NULL;
}

/**
 * 循环单链表第 i 个结点后插入值为 x 的新结点
 * @param {LinkNode} head
 * @param {int} i
 * @param {dataType} x
 * @return LindNode
 */
LinkNode *insert(LinkNode *head, int i, dataType x)
{
    LinkNode *p, *q, *my_rear;
    int j;

    // 为新结点分配空间
    p = (LinkNode *)malloc(sizeof(LinkNode));

    // 设置新的结点值
    p->info = x;

    // 如果循环单链表是空的，则新结点的指针域应指向它自己
    if (i < 0)
    {
        printf("插入位置错误\n");
        free(p);
        return head;
    }

    // 在非空单链表最前面插入
    if (i == 0 && !head)
    {
        // 插入
        p->next = p;
        head = p;
        return head;
    }

    // 在非空单链表最前面插入
    if (i == 0 && head)
    {
        // 找到循环单链表最后一个结点
        my_rear = rear(head);
        // 插入
        p->next = head;
        my_rear->next = p;
        return head;
    }

    if (i > 0 && !head)
    {
        printf("无法找到指定的插入位置\n");
        free(p);
        return head;
    }

    // 在非空单链表中插入值为 x 的结点，并且插入位置不是第一个结点
    if (i > 0 && head)
    {
        // 准备从表中第一个结点开始查找
        q = head;
        // 计数开始
        j = 1;
        // 没有找到并且没有找遍整个表
        while (i != j && q->next != head)
        {
            q = q->next;
            j++;
        }

        // 找不到指定插入位置，即 i 的值超过表中结点的个数，则不进行插入
        if (i != j)
        {
            printf("找不到第 %d 个结点\n", i);
            free(p);
            return head;
        }
        else
        {
            // 找到了第 i 个结点，插入 x
            p->next = q->next;
            // 插入
            q->next = p;
            return head;
        }
    }

    return head;
}

/**
 * 循环单链表的删除操作
 * @param {LinkNode} head
 * @param {datatype} x
 * @return LinkNode
 */
LinkNode *dele(LinkNode *head, dataType x)
{
    // q 用于查找值为 x 的结点， pre 指向 q 的前驱结点
    LinkNode *pre = NULL, *q;

    if (!head)
    {
        printf("循环单链表为空！\n");
        return head;
    }

    // 从第一个结点开始准备查找
    q = head;

    while (q->next != head && q->info != x)
    {
        pre = q;
        q = q->next;
    }

    if (q->info != x)
    {
        printf("没有找到 %d 的结点！\n", x);
    }
    else
    {
        if (q != head)
        {
            pre->next = q->next;
            free(q);
        }
        else
        {
            pre = head->next;
            while (pre->next != q)
            {
                pre = pre->next;
            }
            head = head->next;
            pre->next = head;
            free(q);
        }
    }

    return head;
}