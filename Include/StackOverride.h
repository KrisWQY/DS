#include "DS.h"

#define STACK_FULL 	-1
#define STACK_EMPTY -2

typedef int SElemType;

typedef struct {
	SElemType 	data[MAXSIZE];
	int 		top;
} SqStack;

typedef struct {
	SElemType	data[MAXSIZE];
	int 		top1;
	int			top2;
} SqDoubleStack;

typedef struct {
	SElemType		data;
	LinkStackNode	*next;
} LinkStackNode;

typedef struct {
	ListStackNode	*top;
	int				StackSize;
} LinkStack;
