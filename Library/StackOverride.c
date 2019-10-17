#include "Include/StackOverride.h"

Status
ArrayStackPush (
	SqStack		*S,
	SElemType	e
	)
{
	if (S->top == MAXSIZE - 1) {
		return STACK_FULL;
	}

	S->top++;
	S->data[S->top] = e;
	
	return OK;
}

Status
ArrayStackPop (
	SqStack		*S,
	SElemType	*e
	)
{
	if (S->top == -1) {
		return ERROR;
	}

	*e = S->data[S->top];
	S->top--;

	return OK;
}

Status
ArrayDoubleStackPush (
	SqDoubleStack	*S,
	SElemType		e,
	int				StackNum
	)
{
	if (S->top1 + 1 == S->top2) {
		return STACK_FULL;
	}

	if (StackNum == 1) {
		S->data[++S->top1] = e;
	} else if (StackNum == 2) {
		S->data[--S->top2] = e;
	}

	return OK;
}

Status
ArrayDoubleStackPop (
	SqDoubleStack	*S,
	SElemType		*e,
	int				StackNum
	)
{
	if (StackNum == 1) {
		if (S->top1 == -1) {
			return STACK_EMPTY;
		}
		*e = S->data[S->top1--];
	} else if (StackNum == 2) {
		if (S->top2 == MAXSIZE) {
			return STACK_EMPTY;
		}
		*e = S->data[S->top2++];
	}

	return OK;
}

Status
LinkStackPush (
	LinkStack	*S,
	SElemType	e
	)
{
	LinkStackNode	*P = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	P->data = e;
	P->next = S->top;
	S->top = P;
	S->StackSize++;

	return OK;
}

Status
LinkStackPop (
	LinkStack	*S,
	SElemType	*e
	)
{
	LinkStackNode	*P;
	
	if (S->StackSize == 0) {
		return STACK_EMPTY;
	}

	*e = S->top->data;
	P = S->top;
	S->top = S->top->next;
	free(P);
	S->StackSize--;
	
	return OK;
}