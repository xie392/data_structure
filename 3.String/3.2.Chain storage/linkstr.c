#include "linkstr.h"

/**
 * 链式串的创建
 * @param S     链式串
 * @return void
 */
void strCreate(LinkString *S)
{
    char ch;
    LinkStrNode *p, *r;

    // 用 r 指向链尾
    *S = NULL, r = NULL;

    // 输入字符串
    while ((ch = getchar()) != '\n')
    {
        // 生成新结点
        p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data = ch;

        // 插入到链尾
        if (*S == NULL)
        {
            *S = p;
        }
        else
        {
            r->next = p;
        }
        r = p;
    }

    if (r != NULL)
    {
        // 链尾结点指针域置空
        r->next = NULL;
    }
}

/**
 * 插入运算
 * @param S     链式串      LinkString
 * @param pos   插入位置    int
 * @param T     要插入的串  LinkString
 * @return void
 */
void strInsert(LinkString *S, int pos, LinkString T)
{
    int k;
    LinkString p, q;
    p = *S, k = 1;

    // 查找插入位置
    while (p && k < pos - 1)
    {
        p = p->next;
        k++;
    }

    if (!p)
    {
        printf("插入位置非法\n");
        return;
    }

    // 插入
    q = T;
    while (q && q->next)
    {
        q = q->next;
    }

    // q 指向 T 的尾结点
    q->next = p->next;
    // p 指向 T 的头结点
    p->next = T;
}

/**
 * 删除运算
 * @param S     链式串      LinkString
 * @param pos   删除位置    int
 * @param len   删除长度    int
 * @return void
 */
void strDelete(LinkString *S, int pos, int len)
{
    int k;
    LinkString p, q, r;
    p = *S, k = 1, q = NULL;

    // 查找删除位置
    while (p && k < pos)
    {
        q = p;
        p = p->next;
        k++;
    }

    if (!p)
    {
        printf("删除位置非法\n");
        return;
    }

    // 删除
    k = 1;

    while (k < len && p)
    {
        p = p->next;
        k++;
    }

    if (!p)
    {
        printf("删除长度非法\n");
        return;
    }

    if (!q)
    {
        r = *S;
        // 删除位置为第一个结点
        *S = p->next;
    }
    else
    {
        r = q->next;
        q->next = p->next;
    }
    p->next = NULL;

    // 释放被删除结点
    while (r)
    {
        q = r;
        r = r->next;
        free(q);
    }
}

/**
 * 链式串的连接
 * @param S1     链式串      LinkString
 * @param S2     要连接的串  LinkString
 * @return void
 */
void strConcat(LinkString *S1, LinkString S2)
{
    LinkString p;

    if (!(*S1))
    {
        *S1 = S2;
    }
    else
    {
        if (S2)
        {
            p = *S1;
            // 找到 S1 的尾结点
            while (p->next)
            {
                p = p->next;
            }
            // 连接
            p->next = S2;
        }
    }
}

/**
 * 求子串运算
 * @param S     链式串      LinkString
 * @param pos   子串位置    int
 * @param len   子串长度    int
 * @return LinkString
 */
LinkString subString(LinkString *Sub, LinkString S, int pos, int len)
{
    int k;
    LinkString p, q, r, t;
    p = S, k = 1;

    // 查找子串位置
    while (p && k < pos)
    {
        p = p->next;
        k++;
    }

    if (!p)
    {
        printf("子串位置非法\n");
        return NULL;
    }

    r = (LinkString)malloc(sizeof(LinkStrNode));
    r->data = p->data;
    r->next = NULL;

    k = 1;
    // 用 q 指向子串的最后一个字符的位置
    q = r;

    while (p -> next && k < len)
    {
        p = p->next;
        t = (LinkString)malloc(sizeof(LinkStrNode));
        t->data = p->data;
        t->next = NULL;
        q->next = t;
        q = t;
        k++;
    }

    if(k < len)
    {
        printf("子串长度非法\n");
        return NULL;
    }

    q -> next = NULL;
    
    return r;
}

/**
 * 链式串的输出
 * @param S     链式串      LinkString
 * @return void
 */
void strPrint(LinkString S) {
    LinkString p;
    p = S;

    while(p) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}