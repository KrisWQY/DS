#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "DS.h"

#define	QUEUE_FULL	1
#define	QUEUE_EMPTY	2

typedef int QElemType;

typedef struct {
	QElemType	Data;
	QNode		*Next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr	Front;
	QueuePtr	Rear;
} LinkQueue;

typedef struct {
	QElemType	*Base;
	INT32		Front;
	INT32		Rear;
} LinkLoopQueue;

typedef struct {
	QElemType	Data[MAXSIZE];
	INT32 		Front;
	INT32 		Rear;
} SqLoopQueue;

#endif