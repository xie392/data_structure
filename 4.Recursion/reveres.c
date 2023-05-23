#include <stdio.h>

#define MAXSIZE 100
typedef int dataType;
typedef struct
{
    dataType a[MAXSIZE];
    int size;
} sequenceList;


/**
 * 递归实现字符串反转
 * @param list 顺序表
 * @param left 左边界
 * @param right 右边界
 * @return void
*/
void reverse(sequenceList *list, int left, int right)
{
    dataType temp;
    if (left < right)
    {
        reverse(list, left + 1, right - 1);
        // 交换左右两边的元素
        temp = list->a[left];
        list->a[left] = list->a[right];
        list->a[right] = temp;
    }
}

int main()
{
    sequenceList list = {{1, 2, 3, 4, 5}, 5};
    reverse(&list, 0, list.size - 1);
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", list.a[i]);
    }
    printf("\n");
    return 0;
}