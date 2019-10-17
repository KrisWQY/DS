#include"DS.h"

typedef int TElemType;

typedef struct {
	TElemType	Data;
	INT32 		Parent;
} PTNode;

typedef struct {
	PTNode 		Nodes[MAXSIZE];
	INT32		Root;
	INT32		Node;
} PTree;