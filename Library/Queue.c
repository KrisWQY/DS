#include "Include/Queue.h"

DS_STATUS
InitLoopQueue (
	LoopQueue 	*Q
	)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

UINT32
GetLoopQueueLength (
	LoopQueue 	Q
	)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

DS_STATUS
EnLoopQueue (
	LoopQueue	*Q,
	QElemType	e
	)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return QUEUE_FULL;
	}

	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;

	return OK;
}

DS_STATUS
DeLoopQueue (
	LoopQueue 	*Q,
	QElemType	*e
	) 
{
	if (Q->front == Q->rear) {
		return QUEUE_EMPTY;
	}

	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return DS_SUCCESS;
}


