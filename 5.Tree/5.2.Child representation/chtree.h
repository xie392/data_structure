/**
 * 树的孩子表示法
*/
#define m 3                     // 树中每个结点的最大孩子数
typedef char dataType;          // 结点值得类型
typedef struct ctree_node       // 结点的类型
{
    dataType data;              // 结点的值
    struct ctree_node *child[m];// 孩子指针数组
} ctree_node, *ctree;
ctree root;