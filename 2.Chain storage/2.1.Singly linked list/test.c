#include "../slinkist.h"


int main(){
    LinkNode *Head;

    // 初始化单链表
    Head = init();

    for (int i = 0; i <= 10; i++) {
        // 插入到单链表的表头
        Head = insert(Head, i, i);
    }

    // 输出单链表
    printf("单链表中各个结点的值为：");
    print(Head);
    printf("\n");

    // 删除
    for(int i = 0; i < 5; i++) {
        Head = delete(Head, i);
    }

    // 输出单链表
    printf("单链表中各个结点的值为：");
    print(Head);
    printf("\n");

}