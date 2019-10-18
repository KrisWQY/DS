#include <Include/Stack.h>

DS_STATUS
InitSqStack (
	SqStack *S
	)
{
	S->Base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->Base) {
		exit(OVERFLOW);
	}
	S->Top = S->Base;
	S->StackSize = STACK_INIT_SIZE;
	return DS_SUCCESS;
}

DS_STATUS
DestroySqStack (
	SqStack *S
	)
{
	return DS_SUCCESS;
}

DS_STATUS 
Stack_Clear (
	SqStack *S
	)
{
	return DS_SUCCESS;
}

BOOLEAN 
IsEmptySqStack (
	SqStack *S
	)
{
	if (S->Top == S->Base) {
		return TRUE;
	} else {
		return FALSE;
	}
}

INT32
GetSqStackLength (
	SqStack *S
	) 
{
	return S->StackSize;
}

DS_STATUS
GetSqStackTop (
	SqStack 	S, 
	SElemType 	*Elem
	)
{
	if (S.Top == S.Base) {
		return ERROR;
	}
	*Elem = *(S.Top - 1);
	
	return DS_SUCCESS;
}

DS_STATUS
PushSqStack (
	SqStack 	*S, 
	SElemType 	Elem
	)
{
	if (S->Top - S->Base >= S->StackSize) {
		S->Base = (SElemType *)realloc(S->Base, (S->StackSize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S->Base) {
			exit(OVERFLOW);
		}
		S->Top = S->Base + S->StackSize;
		S->StackSize += STACK_INCREMENT;
	}
	*S->Top = Elem;
	S->Top++;

	return DS_SUCCESS;
}

DS_STATUS 
PopSqStack (
	SqStack 	*S,
	SElemType 	*Elem
	)
{
	if (S->Top == S->Base) {
		return DS_STACK_EMPTY;
	}
	S->Top--;
	*Elem = *(S->Top);

	return DS_SUCCESS;
}

DS_STATUS
TraverseSqStack (
	SqStack 	S, 
	DS_STATUS (*visit) ()
	) 
{
	return DS_SUCCESS;
}



// 3.4
OperandType EvaluateExpression() {
	Stack_Init(OPTR);
	Stack_Push(OPTR, '#');
	Stack_Init(OPND);
	c = getchar();
	while (c != '#' || Stack_GetTop(OPTR) != '#') {
		if (!In(c, OP)) {
			Push((OPND, c);
			c = getchar();
		}
		else {
			switch (Precede(GetTop(OPTR), c)) {
			case'<':
				Stack_Push(OPTR, c);
				c = getchar();
				break;
			case'=':
				Stack_Push(OPTR, x);
				c = getchar();
				break;
			case'>':
				Stack_Pop(OPTR, thera);
				Stack_Pop(OPND, b);
				Stack_Pop(OPND, a);
				Stack_Push(OPND, operate(a, theta, b));
				break;
			}
		}
	}
	return Stack_GetTop(OPND);
}

// 3.5 P55
void Hanoi(INT32 n, char x, char y, char z) {
	INT32 c = 0;
	prINT32f("%i. Move disk %i from %c to %c\n", ++c, n, x, z);
	if (n == 1)
		move(x, 1, z);
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

// 3.6 P65
void Bank_Simulation(INT32 CloseTime) {
	OpenForDay();
	while (MoreEvent) {
		EventDrived(OccurTime, EventType);
		switch (EventType){
		case'A':CustomerArrived(); break;
		case'D':CustomerDeparture(); break;
		default:Invalid();break;
		}

	}
}

// 3.7 P67
void OpenForDay() {
	TotalTime = 0;
	CustomerNum = 0;
	InitList(ev);
	en.OccurTime = 0;
	en.NType = 0;
	OrderInsert(ev, en, cmp);
	for (i = 1; i <= 4; ++i)
		InitQueue(q[i]);
}

void CustomerArrived() {
	++CustomerNum;
	Random(durtime, INT32ertime);
	t = en.OccurTime + INT32ertime;
	if (t < CloseTime)
		OrderInsert(ev, (t, 0), cmp);
	i = Minimum(q);
	EnQueue(q[i], (en.OccurTime, durtime));
	if (QueueLength(q[i]) == 1)
		OrderInsert(ev, (en.OccurTime + durtime, i), cmp);
}

void CustomerDeparture() {
	i = en.NType;
	DelQueue(q[i], customer);
	TotalTime += en.Occurtime - customer.ArrivalTime;
	if (!QueueEmpty(q[i])) {
		GetHead(q[i], customer);
		OrderInsert(ev, (en.OccurTime + customer.Duration, i), (*cmp)());
	}
} 