#include <Include/Stack.h>

VOID
ConvertDec2Oct (
	UINT32	Dec
	)
{
	SqStack	*S;

	Stack_Init(S);
	while (Dec) {
		Stack_Push(S, Dec % 8);
	}

	while (!IsEmptySqStack(S)) {
		PopSqStack(S, )
	}

}

VOID
EditLine (
	VOID
	) 
{
	SqStack S;
	Stack_Init(&S);
	ch = getchar();
	while (ch != EOF) {
		while (ch != EOF &&ch != '\n') {
			switch (ch){
				case '#':Pop(S, c); break;
				case '@':Stack_Clear(&S); break;
				default:break;   
			}

			
		}
	}
}

DS_STATUS
CaculateMazePath (

	)
{

}