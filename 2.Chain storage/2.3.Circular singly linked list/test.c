#include "clnklist.c"

int main() {
    LinkNode *head = init();

    // 插入
    for(int i = 0; i < 10; i++) {
        head = insert(head,i,i);
    }

    printf("所有结点值为：");
    print(head);
    printf("\n");

    // 删除
    for(int i = 0; i < 5; i++) {
        head = dele(head,i);
    }

    printf("所有结点值为：");
    print(head);
    printf("\n");
}