#include "sequence.h"

/**
 * ========
 * 顺序队列
 * ========
 */

/**
 * 初始化队列
 * @param {SeqQueue} *Q
 */
void InitQueue(SeqQueue *Q) {
    Q->front = Q->rear = 0;
}

/**
 * 判断队列是否为空
 * @param {SeqQueue} Q
 * @return {int} 1: 空 0: 非空
 */
int IsEmpty(SeqQueue Q) {
    return Q.front == Q.rear;
}

/**
 * 打印队列的节点值
 * @param {SeqQueue} Q
 */
void PrintQueue(SeqQueue Q) {
    int i;
    if (IsEmpty(Q)) {
        printf("队列为空\n");
    } else {
        for (i = Q.front; i < Q.rear; i++) {
            printf("%5d ", Q.data[i]);
        }
    }
}

/**
* 取得队列的队首节点值
 * @param {SeqQueue} Q
 * @return dataType
*/
dataType GetHead(SeqQueue Q) {
    if (IsEmpty(Q)) {
        printf("队列为空\n");
        exit(1);
    }
    return Q.data[Q.front];
}

/**
 * 队列的插入操作
 * @param {SeqQueue} *Q
 * @param {dataType} x
 */
 void EnQueue(SeqQueue *Q, dataType x) {
    if (Q->rear == MAXSIZE) {
        printf("队列已满\n");
        exit(1);
    }
    Q->data[Q->rear] = x;
    Q->rear++;
}

/**
 * 队列的删除操作
 * @param {SeqQueue} *Q
 */
void DeQueue(SeqQueue *Q) {
    if (IsEmpty(*Q)) {
        printf("队列为空\n");
        exit(1);
    }
    Q->front++;
}


/**
 * =========
 * 循环队列
 * =========
 */

/**
 * 循环队列的插入操作
 * @param {SeqQueue} *Q
 * @param {dataType} x
 */
void EnQueue2(SeqQueue *Q, dataType x) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        printf("队列已满\n");
        exit(1);
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}


/**
 * 循环队列的删除操作
 * @param {SeqQueue} *Q
 */
void DeQueue2(SeqQueue *Q) {
    if (IsEmpty(*Q)) {
        printf("队列为空\n");
        exit(1);
    }
    Q->front = (Q->front + 1) % MAXSIZE;
}
