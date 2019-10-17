#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "DS.h"

#define	QUEUE_FULL	-1
#define	QUEUE_EMPTY	-2

typedef int QElemType;

typedef struct {
	QElemType	data[MAXSIZE];
	int 		front;
	int 		rear;
} LoopQueue;

#endif