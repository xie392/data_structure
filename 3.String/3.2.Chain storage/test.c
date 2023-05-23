#include "linkstr.c"

int main()
{
    LinkString S, T;
    int pos;

    printf("创建字符串 S: ");
    strCreate(&S);

    printf("创建字符串 T: ");
    strCreate(&T);

    printf("插入字符串位置: ");
    scanf("%d", &pos);
    strInsert(&S, pos, T);

    printf("结果:");
    strPrint(S);
    return 0;
}