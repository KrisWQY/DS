#ifndef __STACK_H__
#define __STACK_H__

#include "DS.h"

#define STACK_INIT_SIZE 	100
#define STACK_INCREMENT 	10

#define DS_STACK_EMPTY		1
#define DS_STACK_FULL		2

typedef int SElemType;

typedef struct {
	SElemType *Base;
	SElemType *Top;
	int StackSize;
} SqStack;

DS_STATUS
InitSqStack (
	SqStack *S
	);

DS_STATUS
PushSqStack (
	SqStack 	*S, 
	SElemType 	*Elem
	);

DS_STATUS 
PopSqStack (
	SqStack 	*S,
	SElemType 	*Elem
	);

#endif
