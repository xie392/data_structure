#include "slinklish.c"

int main(){
	node *p;
	// 创建空的单链表
	p = init();

    // 插入元素
    p = insert(p, 0, 0);
    p = insert(p, 1, 1);
    p = insert(p, 2, 2);
    p = insert(p, 3, 3);


    printf("插入单链表成功!\n");

    // 输出单链表
    display(p);

    // 删除
    dele(p, 2);

    printf("\n删除单链表成功!\n");

	return 0;
}
