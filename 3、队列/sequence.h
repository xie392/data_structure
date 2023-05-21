//
// Created by xie392 on 2023/5/21.
//

#ifndef DATA_STRUCTURE_SEQUENCE_H
#define DATA_STRUCTURE_SEQUENCE_H

#endif //DATA_STRUCTURE_SEQUENCE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int dataType;
typedef struct {
    dataType data[MAXSIZE];
    int front;
    int rear;
} SeqQueue;
