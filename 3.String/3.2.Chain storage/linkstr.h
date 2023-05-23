#include <stdio.h>

typedef struct node {
    // 用于存放字符串中每个字符
    char data;
    // 用于指向下一个字符对于结点的指针
    struct node *next;
} LinkStrNode;
typedef LinkStrNode *LinkString;