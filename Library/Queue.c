#include "Include/Queue.h"

DS_STATUS
InitLinkQueue (
	LinkQueue 	*Q
	)
{
	Q->Front = Q->Rear = (QueuePtr)malloc(sizeof(QNode));
	if (Q->Front = NULL) {
		exit(OVERFLOW);
	} 
	Q->Front->Next = NULL;
	return DS_SUCCESS;
}

DS_STATUS
DestoryLinkQueue (
	LinkQueue 	*Q
	)
{
	while (Q->Front != NULL) {
		Q->Rear = Q->Rear->Next;
		free(Q->Front);
		Q->Front = Q->Rear;
	}

	return DS_SUCCESS;
}

DS_STATUS
EnLinkQueue (
	LinkQueue 	*Q,
	QElemType	Elem
	)
{
	QueuePtr	P;
	
	P = (QueuePtr)malloc(sizeof(QNode));
	if (P == NULL) {
		return exit(OVERFLOW);
	}

	P->Data = Elem;
	P->Next = NULL;
	Q->Rear->Next = P;
	Q->Rear = P;

	return DS_SUCCESS;
}

DS_STATUS
DeLinkQueue (
	LinkQueue 	*Q,
	QElemType	*Elem
	)
{
	QueuePtr	P;
	P = (QueuePtr)malloc(sizeof(QNode));
	
	if (Q->Front == Q->Rear) {
		return QUEUE_EMPTY;
	}

	P = Q->Front->Next;
	Elem = P->Data;
	Q->Front->Next = P->Next;
	
	if (Q->Rear == P) {
		Q->Rear = Q->Front;
	}
	free(P);

	return DS_SUCCESS;
}

DS_STATUS
InitSqLoopQueue (
	SqLoopQueue 	*Q
	)
{
	Q->Front = 0;
	Q->Rear = 0;
	return OK;
}

UINT32
GetSqLoopQueueLength (
	SqLoopQueue 	Q
	)
{
	return (Q.Rear - Q.Front + MAXSIZE) % MAXSIZE;
}

DS_STATUS
EnSqLoopQueue (
	SqLoopQueue		*Q,
	QElemType		Elem
	)
{
	if ((Q->Rear + 1) % MAXSIZE == Q->Front) {
		return QUEUE_FULL;
	}

	Q->Data[Q->Rear] = Elem;
	Q->Rear = (Q->Rear + 1) % MAXSIZE;

	return DS_SUCCESS;
}

DS_STATUS
DeSqLoopQueue (
	SqLoopQueue 	*Q,
	QElemType		*e
	) 
{
	if (Q->Front == Q->Rear) {
		return QUEUE_EMPTY;
	}

	*e = Q->Data[Q->Front];
	Q->Front = (Q->Front + 1) % MAXSIZE;

	return DS_SUCCESS;
}


