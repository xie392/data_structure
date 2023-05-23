#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct
{
    char str[MAXSIZE];
    int length;
} SeqString;

/**
 * 字符串朴素的模式匹配算法
 * @param S 主串    SeqString
 * @param T 模式串  SeqString
 * @return int
 */
int index(SeqString p, SeqString t)
{
    int i, j, succ;

    i = 0;
    // 用 i 扫描正文 t , succ 为匹配成功的标志
    succ = 0;

    while (j <= t.length - p.length && !succ)
    {
        // 用 j 扫描主串 t
        j = 0;
        succ = 1;

        while (j < p.length && succ)
        {
            // 用 j 扫描模式串 p
            if (p.str[i] == t.str[i + j])
            {
                // 对应字符相等
                j++;
            }
            else
            {
                // 对应字符不等
                succ = 0;
            }
        }
        ++i;
    }

    return succ ? i - 1 : -1;
}

int main() {
    SeqString p, t;
    int i, pos;

    printf("请输入主串 t: ");
    scanf("%s", t.str);
    printf("请输入模式串 p: ");
    scanf("%s", p.str);

    for (i = 0; t.str[i] != '\0'; i++)
    {
        t.length++;
    }

    for (i = 0; p.str[i] != '\0'; i++)
    {
        p.length++;
    }

    pos = index(p, t);

    if (pos == -1)
    {
        printf("匹配失败\n");
    }
    else
    {
        printf("匹配成功，匹配位置为 %d\n", pos);
    }

    return 0;
}