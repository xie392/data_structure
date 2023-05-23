#include "sequence.c"

int main() {
    SeqQueue Q;

    // 初始化队列
    InitQueue(&Q);

    // 入队
    for (int i = 0; i < 10; i++) {
        EnQueue(&Q, i);
    }

    // 打印队列
    printf("队列中的元素为：");
    PrintQueue(Q);
    printf("\n");

    // 出队
    for (int i = 0; i < 5; i++) {
        DeQueue(&Q);
    }

    // 打印队列
    printf("队列中的元素为：");
    PrintQueue(Q);
    printf("\n");
}