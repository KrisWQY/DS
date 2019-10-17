#ifndef __LIST_H__
#define __LIST_H__

#include "DS.h"


#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10


typedef int ElemType;
typedef void VOID;

typedef struct {
	ElemType data;
	ListNode *next;
} ListNode;

#endif