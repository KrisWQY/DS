#include<Include/List.h>

//
// 3.7
//
Status
GetElem (
	pLinkList 	L,
	int 		i,
	ElemType	*e
	)
{

}
//
// 3.9 - Head node insertion
//
VOID
CreateListHead (
	ListNode 	**L,
	int			nums
	)
{
	ListNode	*p;
	int			idx;
	*L = (ListNode*)malloc(sizeof(ListNode));
	(*L)->next = NULL;
	for (idx = 0; idx < nums; idx++) {
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = 0;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

VOID
CreateListTail (
	ListNode	**L,
	int			nums
	)
{
	ListNode	*p;
	ListNode	*r;
	int			idx;
	*L = (ListNode*)malloc(sizeof(ListNode));
	(*L)->next = NULL;
	r = *L;
	for (idx = 0; idx < nums; idx++) {
		p = (ListNode*)malloc(sizeof(ListNode));
		p->data = 0;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//
// 3.10
//
Status
ClearList (
	ListNode	**L
	)
{
	ListNode	*p;
	ListNode	*q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

