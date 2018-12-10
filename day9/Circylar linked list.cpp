#include<stdio.h>
#include<stdlib.h>
#include"Circylar_linked_lists.h"

//建立头节点（双向循环链表）
PtrtoNode create()	
{
	PtrtoNode header;
	header = (PtrtoNode)malloc(sizeof(struct Node));
	header->element = -1;
	header->Next = header;
	header->Prior = header;
	return header;
}
//插入元素
PtrtoNode Insert(int num, Position p)
{
	PtrtoNode current = (PtrtoNode)malloc(sizeof(struct Node));
	current->Next = p->Next;
	p->Next->Prior = current;
	p->Next = current;
	current->Prior = p;

	current->element = num;
	return current;
}

//删除元素
PtrtoNode Delete(int X, Position L)
{
	Position P, TmpCell;

	P = L->Next;
	TmpCell = L;
	TmpCell->Prior->Next = TmpCell->Next;
	TmpCell->Next->Prior = TmpCell->Prior;
	TmpCell->Next = TmpCell->Prior = NULL;
	free(TmpCell);
	return P;
}
