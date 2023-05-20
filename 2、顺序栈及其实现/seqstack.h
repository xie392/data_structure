//
// Created by xie392 on 2023/5/20.
//

#ifndef DATA_STRUCTURE_SEQSTACK_H
#define DATA_STRUCTURE_SEQSTACK_H

#endif //DATA_STRUCTURE_SEQSTACK_H

#define MAXSIZE 100
typedef int DataType;
typedef struct {
    DataType data[MAXSIZE];
    int top;
} SeqStack;

#include <stdio.h>
#include <stdlib.h>