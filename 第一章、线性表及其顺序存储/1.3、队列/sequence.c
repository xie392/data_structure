#include "sequence.h"

/**
 * ===================================================================================================================
 * ˳�����
 * ===================================================================================================================
 */

/**
 * ��ʼ������
 * @param {SeqQueue} *Q
 */
void InitQueue(SeqQueue *Q) {
    Q->front = Q->rear = 0;
}

/**
 * �ж϶����Ƿ�Ϊ��
 * @param {SeqQueue} Q
 * @return {int} 1: �� 0: �ǿ�
 */
int IsEmpty(SeqQueue Q) {
    return Q.front == Q.rear;
}

/**
 * ��ӡ���еĽڵ�ֵ
 * @param {SeqQueue} Q
 */
void PrintQueue(SeqQueue Q) {
    int i;
    if (IsEmpty(Q)) {
        printf("����Ϊ��\n");
    } else {
        for (i = Q.front; i < Q.rear; i++) {
            printf("%5d ", Q.data[i]);
        }
    }
}

/**
* ȡ�ö��еĶ��׽ڵ�ֵ
 * @param {SeqQueue} Q
 * @return dataType
*/
dataType GetHead(SeqQueue Q) {
    if (IsEmpty(Q)) {
        printf("����Ϊ��\n");
        exit(1);
    }
    return Q.data[Q.front];
}

/**
 * ���еĲ������
 * @param {SeqQueue} *Q
 * @param {dataType} x
 */
 void EnQueue(SeqQueue *Q, dataType x) {
    if (Q->rear == MAXSIZE) {
        printf("��������\n");
        exit(1);
    }
    Q->data[Q->rear] = x;
    Q->rear++;
}

/**
 * ���е�ɾ������
 * @param {SeqQueue} *Q
 */
void DeQueue(SeqQueue *Q) {
    if (IsEmpty(*Q)) {
        printf("����Ϊ��\n");
        exit(1);
    }
    Q->front++;
}


/**
 * ===================================================================================================================
 * ѭ������
 * ===================================================================================================================
 */

/**
 * ѭ�����еĲ������
 * @param {SeqQueue} *Q
 * @param {dataType} x
 */
void EnQueue2(SeqQueue *Q, dataType x) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        printf("��������\n");
        exit(1);
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}


/**
 * ѭ�����е�ɾ������
 * @param {SeqQueue} *Q
 */
void DeQueue2(SeqQueue *Q) {
    if (IsEmpty(*Q)) {
        printf("����Ϊ��\n");
        exit(1);
    }
    Q->front = (Q->front + 1) % MAXSIZE;
}
