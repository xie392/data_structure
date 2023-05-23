#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int dataType;
typedef struct
{
    dataType data[MAXSIZE];
    int size;
} SeqList;
