//
// Created by 26363 on 2023/5/18.
//
#include "sequlist.c"

int main(){
    SeqList list;

    // 初始化顺序表
    init(&list);

    // 在顺序表后面插入元素
    for(int i = 0; i < 10; i++){
        append(&list, i);
    }

    // 在索引为 5 的位置插入元素 100
    insert(&list, 5, 100);

    // 删除索引为 2 的元素
    delete(&list, 2);

    // 修改索引为 3 的元素
    update(&list, 3, 200);

    // 取出索引为 4 的元素
    printf("索引为 4 的元素为：%d\n", get(&list, 4));

    // 打印顺序表的各个元素
    print(&list);

    return 0;
}