# 顺序表的实现

线性表采用顺序存储的方式存储就称为顺序表。顺序表是将表中的结点依次存放在计算机内存中一组连续的存储单元里。

## 顺序表图解插入和删除

![顺序表图解实现](./accets/excalidraw-animate.svg)

## 顺序表类型定义

```c
#define MAXSIZE 100
typedef int dataType;
typedef struct {
    dataType data[MAXSIZE];
    int size;
} SeqList;
```

## 顺序表的初始化

```c
void init(SeqList *list) {
    list->size = 0;
}
```

## 判断顺序表是否为空
    
```c
int isEmpty(SeqList *list) {
    return list->size == 0;
}
```

## 在顺序表后面插入元素

```c
void append(SeqList *list, dataType data) {
    if (list->size == MAXSIZE) {
        printf("顺序表已满，无法插入！\n");
        exit(1);
    }
    // 将元素插入到顺序表的最后
    list->data[list->size] = data;
    // 顺序表的长度加一
    list->size++;
}
```

## 打印顺序表的各个元素

```c
void print(SeqList *list) {
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 打印顺序表的各个元素
    for (int i = 0; i < list->size; ++i) {
        printf("%5d ", list->data[i]);
    }
}
```

## 查找顺序表中的元素

```c
int find(SeqList *list, dataType data) {
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 顺序查找顺序表中的元素
    for (int i = 0; i < list->size; ++i) {
        // 如果找到了，就返回元素的下标
        if (list->data[i] == data) {
            return i;
        }
    }
    return -1;
}
```

## 删除顺序表中的元素
    
```c
void delete(SeqList *list, dataType data) {
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 查找要删除的元素
    int index = find(list, data);
    // 如果找到了，就删除元素
    if (index != -1) {
        // 将元素后面的元素向前移动
        // [1,2,3] => 删除2 => [1,3], i = 1 开始
        // i = 1 => data[1] = data[2] = 3
        for (int i = index; i < list->size - 1; ++i) {
            list->data[i] = list->data[i + 1];
        }
        // 顺序表的长度减一
        list->size--;
    }
}
```

## 取出顺序表中某个元素的值

```c
dataType get(SeqList *list, int index) {
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 判断下标是否合法
    if (index < 0 || index >= list->size) {
        printf("下标不合法！\n");
        exit(1);
    }
    return list->data[index];
}
```

## 插入元素到顺序表中的某个位置

```c
void insert(SeqList *list, int index, dataType data) {
    int i;
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 判断下标是否合法
    if (index < 0 || index >= list->size) {
        printf("下标不合法！\n");
        exit(1);
    }
    // 判断顺序表是否已满
    if (list->size == MAXSIZE) {
        printf("顺序表已满，无法插入！\n");
        exit(1);
    }
    // 将元素插入到顺序表的指定位置
    // [1,2,3] => 插入4到下标为1的位置 => [1,4,2,3], i = 2 开始
    // i = 2 => data[2] = data[1] = 2
    for (i = list->size - 1; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = data;
    // 顺序表的长度加一
    list->size++;
}
```

## 修改顺序表中某个元素的值

```c
void update(SeqList *list, int index, dataType data) {
    // 判断顺序表是否为空
    if (isEmpty(list)) {
        printf("顺序表为空！\n");
        exit(1);
    }
    // 判断下标是否合法
    if (index < 0 || index >= list->size) {
        printf("下标不合法！\n");
        exit(1);
    }
    list->data[index] = data;
}
```
