#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int DataType;
typedef struct {
    DataType data[MAXSIZE];
    int top;
} SeqStack;

