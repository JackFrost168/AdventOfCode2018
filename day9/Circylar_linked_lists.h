typedef struct Node *PtrtoNode;
typedef PtrtoNode Position;
typedef PtrtoNode List;

//结构体声明
struct Node
{
	int element;
	struct Node *Next;
	struct Node *Prior;
};

PtrtoNode create();
PtrtoNode Insert(int num, Position p);
PtrtoNode Delete(int X, Position L);
