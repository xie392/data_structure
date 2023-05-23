/**
 * 树的双亲表示法的头文件，文件名：ptree.h
 */
#define MAXSIZE 100             // 树中结点的最大个数
typedef char dataType;          // 结点值得类型
typedef struct                  // 结点的类型
{
    dataType data;              // 结点的值
    int parent;                 // 结点的双亲位置
} ptree_node;

typedef struct                  // 树的类型
{
    ptree_node nodes[MAXSIZE];  // 结点数组
    int length, root;           // 树中实际所含结点数和根的位置
} ptree;