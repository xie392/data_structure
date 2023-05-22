#include "sequlist.h"
/**
 * ��ʼ��˳���
 * @param list      ˳���
 * @return
 */
void init(SeqList *list) {
    list->size = 0;
}

/**
 * �ж�˳����Ƿ�Ϊ��
 * @param list      ˳���
 * @return
 */
int isEmpty(SeqList *list) {
    return list->size == 0;
}

/**
 * ��˳���������Ԫ��
 * @param list      ˳���
 * @param data      Ҫ�����Ԫ��
 * @return
 */
void append(SeqList *list, dataType data) {
    if (list->size == MAXSIZE) {
        printf("˳����������޷����룡\n");
        exit(1);
    }
    // ��Ԫ�ز��뵽˳�������
    list->data[list->size] = data;
    // ˳���ĳ��ȼ�һ
    list->size++;
}

/**
 * ��ӡ˳���ĸ���Ԫ��
 * @param list      ˳���
 * @return
 */
void print(SeqList *list) {
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // ��ӡ˳���ĸ���Ԫ��
    for (int i = 0; i < list->size; ++i) {
        printf("%5d ", list->data[i]);
    }
}

/**
 * ����˳����е�Ԫ��
 * @param list      ˳���
 * @param data      Ҫ���ҵ�Ԫ��
 * @return          Ԫ�ص��±�
 */
int find(SeqList *list, dataType data) {
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // ˳�����˳����е�Ԫ��
    for (int i = 0; i < list->size; ++i) {
        // ����ҵ��ˣ��ͷ���Ԫ�ص��±�
        if (list->data[i] == data) {
            return i;
        }
    }
    return -1;
}

/**
 * ɾ��˳����е�Ԫ��
 * @param list      ˳���
 * @param data      Ҫɾ����Ԫ��
 * @return
 */
void delete(SeqList *list, dataType data) {
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // ����Ҫɾ����Ԫ��
    int index = find(list, data);
    // ����ҵ��ˣ���ɾ��Ԫ��
    if (index != -1) {
        // ��Ԫ�غ����Ԫ����ǰ�ƶ�
        // [1,2,3] => ɾ��2 => [1,3], i = 1 ��ʼ
        // i = 1 => data[1] = data[2] = 3
        for (int i = index; i < list->size - 1; ++i) {
            list->data[i] = list->data[i + 1];
        }
        // ˳���ĳ��ȼ�һ
        list->size--;
    }
}

/**
 * ȡ��˳�����ĳ��Ԫ�ص�ֵ
 * @param list      ˳���
 * @param index     Ԫ�ص��±�
 * @return          Ԫ�ص�ֵ
 */
dataType get(SeqList *list, int index) {
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // �ж��±��Ƿ�Ϸ�
    if (index < 0 || index >= list->size) {
        printf("�±겻�Ϸ���\n");
        exit(1);
    }
    return list->data[index];
}

/**
* ����Ԫ�ص�˳����е�ĳ��λ��
 * @param list      ˳���
 * @param index     Ԫ�ص��±�
 * @param data      Ҫ�����Ԫ��
*/
void insert(SeqList *list, int index, dataType data) {
    int i;
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // �ж��±��Ƿ�Ϸ�
    if (index < 0 || index >= list->size) {
        printf("�±겻�Ϸ���\n");
        exit(1);
    }
    // �ж�˳����Ƿ�����
    if (list->size == MAXSIZE) {
        printf("˳����������޷����룡\n");
        exit(1);
    }
    // ��Ԫ�ز��뵽˳����ָ��λ��
    // [1,2,3] => ����4���±�Ϊ1��λ�� => [1,4,2,3], i = 2 ��ʼ
    // i = 2 => data[2] = data[1] = 2
    for (i = list->size - 1; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = data;
    // ˳���ĳ��ȼ�һ
    list->size++;
}

/**
 * �޸�˳�����ĳ��Ԫ�ص�ֵ
 * @param list      ˳���
 * @param index     Ԫ�ص��±�
 * @param data      Ԫ�ص�ֵ
 */
void update(SeqList *list, int index, dataType data) {
    // �ж�˳����Ƿ�Ϊ��
    if (isEmpty(list)) {
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }
    // �ж��±��Ƿ�Ϸ�
    if (index < 0 || index >= list->size) {
        printf("�±겻�Ϸ���\n");
        exit(1);
    }
    list->data[index] = data;
}