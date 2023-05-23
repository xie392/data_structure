#include "seqstring.h"

/**
 * 顺序串的插入
 * @param S     指向 SeqString 类型的指针变量
 * @param pos   插入位置 int
 * @param T     T 为 SeqString 类型，表示插入的字符串
 * @return void
*/
void StrInsert(SeqString *S, int pos, SeqString T)
{
    int i;

    // 处理非法情况
    if (pos < 0 || pos > S->length +1 || S ->length + T.length > MAXSIZE - 1)
    {
        printf("插入位置非法！\n");
        exit(1);
    }

    // S 中从第 i 个字符开始，依次向后移动 T.length 个位置，给新的 T 腾出空间
    for (i = S->length - 1; i >= pos; i--)
        S->str[i + T.length] = S->str[i];

    // 将 T 中的字符依次插入到 S 中
    for (i = 0; i < T.length; i++)
        S->str[pos + i] = T.str[i];

    S->length = S->length + T.length;
    // 设置字符串 S 的结束标志
    S -> str[S -> length] = '\0';
}


/**
 * 顺序串的删除
 * @param S     指向 SeqString 类型的指针变量
 * @param pos   删除位置 int
 * @param len   删除长度 int
 * @return void
*/
void StrDelete(SeqString *S, int pos, int len)
{
    int i;

    // 处理非法情况
    if (pos < 0 || pos > S->length - 1 || len < 0 || len > S->length - pos)
    {
        printf("删除位置非法！\n");
        exit(1);
    }

    // S 中从第 i 个字符开始，依次向前移动 len 个位置，覆盖要删除的字符
    for (i = pos + len; i <= S->length - 1; i++)
        S->str[i - len] = S->str[i];

    S->length = S->length - len;
    // 设置字符串 S 的结束标志
    S -> str[S -> length] = '\0';
}

/**
 * 顺序串的连接
 * @param S1     S1 为 SeqString 类型，表示连接的字符串
 * @param S2     S2 为 SeqString 类型，表示连接的字符串
 * @return SeqString
*/
SeqString *Strconcat(SeqString S1, SeqString S2)
{
    int i;
    SeqString *p;

    // 处理非法情况
    if (S1.length + S2.length > MAXSIZE - 1)
    {
        printf("连接后字符串长度超过 MAXSIZE！\n");
        exit(1);
    }

    // 申请一个新的字符串空间
    p = (SeqString *)malloc(sizeof(SeqString));

    // 将 S1 中的字符复制到新的字符串空间中
    for (i = 0; i < S1.length; i++)
        p->str[i] = S1.str[i];
    
    // 将 S2 中的字符复制到新的字符串空间中
    for (i = 0; i < S2.length; i++)
        p->str[S1.length + i] = S2.str[i];

    p->length = S1.length + S2.length;

    // 设置字符串 S 的结束标志
    p -> str[p -> length] = '\0';
    
    return p;
}

/**
 * 求给定顺序串的子串
 * @param S     指向 SeqString 类型的指针变量
 * @param pos   子串的起始位置 int
 * @param len   子串的长度 int
 * @return SeqString
*/
SeqString *substring(SeqString S, int pos, int len) {
    int k = 0;

    SeqString *p;

    // 处理非法情况
    if (pos < 1 || pos > S.length  || pos + len  - 1 > S.length)
    {
        printf("求子串位置非法！\n");
        return NULL;
    }

    // 申请一个新的字符串空间
    p = (SeqString *)malloc(sizeof(SeqString));

    // 将 S 中的字符复制到新的字符串空间中
    for (k = 0; k < len; k++)
        p->str[k] = S.str[pos + k - 1];

    p->length = len;

    // 设置字符串 S 的结束标志
    p -> str[p -> length] = '\0';

    return p;
}