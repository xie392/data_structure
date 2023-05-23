#include "seqstring.c"
#include <string.h>

int main()
{
    SeqString S, T1,T2;

    T1.str[0] = 'a';
    T1.str[1] = 'b';
    T1.length = 2;

    StrInsert(&S, 0, T1);
    printf("在 0 处插入 '%s': %s\n", T1.str, S.str);

    T2.str[0] = 'c';
    T2.length = 1;
    StrInsert(&S, 1, T2);  
    printf("在 1 处插入 '%s': %s\n",T2.str, S.str);

    // 删除
    StrDelete(&S, 0, 1);
    printf("在 0 处删除，长度为 1: %s\n",S.str);

    SeqString *str;
    // 拼接
    str = Strconcat(T1, T2);
    printf("拼接 '%s' 和 '%s': %s\n", T1.str, T2.str, str);

    return 0;
}