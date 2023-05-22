#include "hlinkist.c"

int main() {
    // 初始化单链表
    LinkNode *head = init();

    // 插入
    for(int i = 0; i <= 10; i++) {
        insert(head, i, i);
    }

    // 打印
    printf("所有结点值为：");
    print(head);
    printf("\n");

    // ?删除
    for(int i = 0; i < 5; i++) {
        dele(head, i);
    }

    printf("所有结点值为：");
    print(head);
    printf("\n");

    return 0;
}