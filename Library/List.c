#include <stdio.h>
#include <stdlib.h>

#include "Include/SqList.h"
#include "Include/LinkList.h"

int main()
{
	printf("Hello World!\n");	
	return 0;
}


// SqList function start>>>
// 2.1
void SqList_Union(SqList *La, SqList *Lb) {
	int La_len, Lb_len;
	int e;
	La_len = SqList_Length(La);
	Lb_len = SqList_Length(Lb);
	for (int i = 1; i <= Lb_len; i++) {
		SqList_GetElem(La, i, &e);
		if (!SqList_LocateElem(La, e, Compare))
			SqList_Insert(La, ++La_len, e);
	}
}

int SqList_Length(SqList *L) {
	return L->length;
}

void SqList_GetElem(SqList *L, int i, ElemType *e) {
	e = &(L->elem[i - 1]);
}

int SqList_IsEmpty(SqList *L) {
	return L->length ? NOTEMPTY : EMPTY;
}

// 2.2
Status SqList_Merge(SqList *La, SqList *Lb, SqList *Lc) {
	int i, j, k;
	int La_len, Lb_len;
	int *ai, *bj;
	SqList_Init(Lc);
	i = j = 1;
	k = 0;
	La_len = SqList_Length(La);
	Lb_len = SqList_Length(Lb);
	while ((i <= La_len) && (j <= Lb_len)) {
		SqList_GetElem(La, i, ai);
		SqList_GetElem(Lb, j, bj);
		if (*ai <= *bj) {
			SqList_Insert(Lc, ++k, *ai);
			++i;
		}
		else {
			SqList_Insert(Lc, ++k, *bj);
			++j;
		}
	}
	while (i <= La_len) {
		SqList_GetElem(La, i++, ai);
		SqList_Insert(Lc, ++k, *ai);
	}
	while (j <= Lb_len) {
		SqList_GetElem(Lb, j++, bj);
		SqList_Insert(Lc, ++k, *bj);
	}
	return OK;
}
// 2.3
Status SqList_Init(SqList *L){
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L->elem){
		exit(OVERFLOW);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

// 2.4
Status SqList_Insert(SqList *L, int i, ElemType e){
	if(i < 1 || i > L->length + 1){
		return ERROR;
	}
	if(L->length >= L->listsize){
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if(!newbase){
			exit(OVERFLOW);
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	ElemType *q = &L->elem[i - 1];
	for(ElemType *p = &L->elem[L->length - 1]; p >= q; --p){
		*(p + 1) = *p;
	}
	*q = e;
	L->length++;
	return OK;
}

// 2.5
Status SqList_Delete(SqList *L, int i, ElemType *e) {
  ElemType *p, *q;
  if (i < 1 || i > L->length) 
	  return ERROR;  
  p = &(L->elem[i - 1]);                   
  *e = L->elem[i - 1];
  q = L->elem + L->length - 1;                
  for (++p; p<=q; ++p) 
	  *(p-1) = *p;
  L->length--;                           
  return OK;
}

// 2.6
int SqList_LocateElem(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType)) {
  int i = 1;
  ElemType *p;        
  p = L->elem;   
  while (i <= L->length && !(*compare)(*p++, e)) 
	  ++i;
  if (i <= L->length) 
	  return i;
  else return 0;
}

Status Compare(ElemType a, ElemType b) {
	return a == b ?  1 : 0;
}

// 2.7
void SqList_Merge2(SqList *La, SqList *Lb, SqList *Lc) {
	ElemType *pa, *pb, *pc, *pa_last, *pb_last;
	pa = La->elem;  
	pb = Lb->elem;
	Lc->listsize = Lc->length = La->length+Lb->length;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize*sizeof(ElemType));
	if (!Lc->elem)
		exit(OVERFLOW);   
	pa_last = La->elem+La->length-1;
	pb_last = Lb->elem+Lb->length-1;
	while (pa <= pa_last && pb <= pb_last) {  
		if (*pa <= *pb) 
			*pc++ = *pa++;
		else 
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
	  *pc++ = *pa++;      
	while (pb <= pb_last) 
	  *pc++ = *pb++;      
}
// SqList function end<<<


// LinkList function start>>>
// 2.8
Status LinkList_GetElem(pLinkList L,int i, ElemType *e) {
  pLinkList p;
  p = L->next;   
  int j = 1;           
  while (p && j < i) {   
	  p = p->next;  
	  ++j;
  }
  if (!p || j > i) 
	  return ERROR;
  *e = p->data;  
  return OK;
}

// 2.9
Status LinkList_Insert(pLinkList L, int i, ElemType e) {
	pLinkList p, s;
	p = L;
	int j = 0;
	while(p && j < i - 1) {
	p = p->next;
	++j;
	}
	if (!p || j > i - 1) 
		return ERROR;
	s = (pLinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// 2.10
Status LinkList_Delete(pLinkList L, int i, ElemType *e) {
	pLinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) 
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

// 2.11 P30
void LinkList_Create(pLinkList L, int n) {
	pLinkList p;
	L = (pLinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--) {
		p = (pLinkList)malloc(sizeof(LNode));
		scanf(&(p->data));
		p->next = L->next;
		L->next = p;
	}
}

// 2.12 P31
void LinkList_Merge(pLinkList La, pLinkList Lb, pLinkList Lc) {
	pLinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}
/*
void LinkList_ReverseCreate(pLinkList L, int n) {
	pLinkList p;
	int i;
	L = (pLinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n; i>0; --i) {
		p = (pLinkList)malloc(sizeof(LNode));
		p->data = random(200);
		p->next = L->next;    
		L->next = p;
	}
}

void LinkList_Merge(pLinkList La, pLinkList Lb, pLinkList Lc) {
	pLinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;   pc = pa;   pa = pa->next;
		}
		else { pc->next = pb;   pc = pb;   pb = pb->next; }
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}*/
// LinkList function end<<<

// Static Linklist function start>>>
// 2.13 P32
int SLinkList_LocateElem(SLinkList S, ElemType e) {
	int i;
	i = S[0].cur;
	while (i && S[i].data != e) i = S[i].cur;
	return i;
}

// 2.14 P33
void SLinkList_InitSpace(SLinkList Space) {
	for (int i = 0; i < MAXSIZE - 1; i++) {
		Space[MAXSIZE - 1].cur = 0;
	}
}

// 2.15 P33
int SLinkList_Malloc(SLinkList Space) {
	int i = Space[0].cur;
	if (Space[0].cur)
		Space[0].cur = Space[i].cur;
	return i;
}

// 2.16 P33
void SLinkList_Free(SLinkList Space, int k) {
	Space[k].cur = Space[0].cur;    
	Space[0].cur = k;
}

// 2.17 P33
void SLinkList_Difference(SLinkList Space, int S) {
	int i, j, k, m, n, p, r;
	ElemType b;
	SLinkList_InitSpace(Space);          
	S = SLinkList_Malloc(Space);
	r = S;
	m = random(2, 8);
	n = random(2, 8);
	printf("  A = ( ");
	initrandom_c1();
	for (j = 1; j <= m; ++j) {
		i = SLinkList_Malloc(Space);
		//printf("i=%d   ",i);
		Space[i].data = random_next_c1();
		printf("%c ", Space[i].data);
		Space[r].cur = i;  
		r = i;
	}
	printf(")\n");
	Space[r].cur = 0;
	initrandom_c1();
	printf("  B = ( ");
	for (j = 1; j <= n; ++j) {
		b = random_next_c1();
		printf("%c ", b);
		p = S;   k = Space[S].cur;
		while (k != Space[r].cur && Space[k].data != b) {
			p = k;    k = Space[k].cur;
		}
		if (k == Space[r].cur) {
			i = SLinkList_Malloc(Space);
			Space[i].data = b;
			Space[i].cur = Space[r].cur;
			Space[r].cur = i;
		}
		else {
			Space[p].cur = Space[k].cur;
			Free_SL(Space, k);
			if (r == k)  r = p;
		}
	}
	printf(")\n");
}
// Static Linklist function end<<<

// Circular and Double-direction Linklist function start>>>
// 2.18 P36
DuLinkList DuLinkList_Insert(DuLinkList L, int i, ElemType e) {
	DuLinkList p,s;
	if (!(p = DuLinkList_GetElem(L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

// 2.19 P36
Status DuLinkList_Delete(DuLinkList L, int i, ElemType e) {
	DuLinkList p, s;
	if (!(p = DuLinkList_GetElem(L, i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}

// 2.20
/*Status DuLinkList_Insert(LinkList L, int i, ElemType e) {
	LinkList h, s;
	if (!LocatePos(L, i - 1, h))
		return ERROR;
	if (!MakeNode(s, e))
		return ERROR;
	InsFirst(h, s);
	return OK;
}*/

// 2.21 P39
Status MergeList_L(LinkList La, LinkList Lb, LinkList Lc,
	int(*compare)(ElemType, ElemType)) {
	LinkList ha, hb;
	Position pa, pb, q;
	ElemType a, b;
	if (!InitList(Lc)) 
		return ERROR;  // �洢�ռ����ʧ��
	ha = GetHead(La);      // ha��hb�ֱ�ָ��La��Lb��ͷ���
	hb = GetHead(Lb);
	pa = NextPos(La, ha);  // pa��pb�ֱ�ָ��La��Lb�е�ǰ���
	pb = NextPos(Lb, hb);
	while (pa && pb) {     // La��Lb���ǿ�
		a = GetCurElem(pa);  // a��bΪ�����е�ǰ�Ƚ�Ԫ��
		b = GetCurElem(pb);
		if ((*compare)(a, b) <= 0) {  // a��b
			DelFirst(ha, q);  Append(Lc, q);  pa = NextPos(La, pa);
		}
		else {   // a��b
			DelFirst(hb, q);  Append(Lc, q);  pb = NextPos(Lb, pb);
		}
	} // while
	if (pa) Append(Lc, pa);        // 
	else Append(Lc, pb);           //
	FreeNode(ha);   FreeNode(hb);  // 
	return OK;
}
//

// 
// 2.22
Status cmp(ElemType a, ElemType b) {
	if (a.expn >= b.expn) return 1;
	else return 0;
}

void CreatPolyn(PLinkList &P, int m) {
	PLink h, q, s;
	PElemType e;
	int i;
	InitList(P);   h = GetHead(P);
	e.coef = 0.0;  e.expn = -1;
	SetCurElem(h, e); 
	for (i = 1; i <= m; ++i) {
		e.coef = (float)(random(1, 90) + random(10) / 10.0);
		if (random(2)) e.coef = -e.coef;
		e.expn = e.expn + random(1, 10); 
		if (!LocateElem(P, e, q, cmp)) {
			if (MakeNode(s, e)) InsFirst(q, s);
			if (q == P.tail) P.tail = s;
		}
		else i--;
	}
}

Status PrintfPoly(PLinkList P) {
	int i = 0;
	PLink q = P.head->next;
	while (q) {
		if (fabs(q->data.coef) > 0.005) {
			if (i>0) {
				if (q->data.coef>0.005) printf(" + ");
				else printf(" - ");
				printf("%.2f", fabs(q->data.coef));
			}
			else printf("%.2f", q->data.coef);
			if (q->data.expn >= 1) printf("x");
			if (q->data.expn>1) printf("^%d", q->data.expn);
		}
		q = q->next;
		if (++i % 6 == 0) printf("\n     ");
	}
	printf("\n");
	return OK;
}

// 2.23
int Compare(PElemType a, PElemType b) {
	if (a.expn<b.expn) return -1;
	if (a.expn>b.expn) return 1;
	return 0;
}

void AddPolyn(PLinkList &Pa, PLinkList &Pb) {
	PLink ha, hb, qa, qb;
	PElemType a, b, temp;
	float sum;
	ha = GetHead(Pa);
	hb = GetHead(Pb);
	qa = NextPos(Pa, ha);
	qb = NextPos(Pb, hb);
	while (qa && qb) {
		a = GetCurElem(qa);
		b = GetCurElem(qb);
		switch (Compare(a, b)) {
		case -1:
			ha = qa;
			qa = NextPos(Pa, qa);
			break;
		case 0:
			sum = a.coef + b.coef;
			if (sum != 0.0) {
				temp.coef = sum;
				temp.expn = a.expn;
				SetCurElem(qa, temp);
				ha = qa;
			}
			else {
				DelFirst(ha, qa);
				FreeNode(qa);
			}
			DelFirst(hb, qb);
			FreeNode(qb);
			qb = NextPos(Pb, hb);
			qa = NextPos(Pa, ha);
			break;
		case 1:
			DelFirst(hb, qb);
			InsFirst(ha, qb);
			qb = NextPos(Pb, hb);
			ha = NextPos(Pa, ha);
			break;
		} // switch
	} // while
	if (!Empty(Pb)) Append(Pa, qb);
	FreeNode(hb);
}