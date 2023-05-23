#include "sequlist.c"

int main(){
    SeqList list;

    /**
     * 初始化顺序表
     */
    init(&list);

    /**
     * 在顺序表后面插入元素
     */
    for(int i = 0; i < 10; i++){
        append(&list, i);
    }

    /**
     * 打印顺序表的各个元素
     */
    insert(&list, 5, 100);

    /**
     * 删除顺序表中的元素
     */
    delete(&list, 2);

    /**
     * 修改顺序表中的元素
     */
    update(&list, 3, 200);

    /**
     * 查找顺序表中的元素
     */
    printf("下标为4的元素: %d\n", get(&list, 4));

    /**
     * 打印顺序表的各个元素
     */
    printf("All List:");
    print(&list);

    return 0;
}