#ifndef __STACK_H__
#define __STACK_H__

#include "DS.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

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
	SqStack *S, 
	SElemType e
	);

DS_STATUS 
PopSqStack (
	SqStack *S,
	SElemType e
	);

#endif
