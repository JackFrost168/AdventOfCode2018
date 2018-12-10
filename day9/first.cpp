#include"Circylar_linked_lists.h"
#include<stdio.h>
#define SIZE 464
#define WORTH 7173000
#include<stdlib.h>

void swap(unsigned int &a,unsigned int &b)
{
	unsigned int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void first()
{
	PtrtoNode header = create();
	PtrtoNode pos = header;	//当前元素位置
	unsigned int person[SIZE] = { 0 };
	for (int i = 0; i < WORTH; ++i)
	{
		if (i % 50000 == 0)
			printf("%d\n", i);
		if (i == 0)
		{
			pos = Insert(i, pos);
			continue;
		}
		if (i % 23 == 0)	//等于23的倍数时进行操作
		{
			person[(i) % SIZE] += i;	//给第(i%SIZE)个人加分
			for (int i = 0; i < 7; ++i)	//前移7位
			{
				pos = pos->Prior;
				if (pos->element == -1)
					pos = pos->Prior;
			}
			
			person[(i) % SIZE] += pos->element;	//给第(i%SIZE)个人加分
			pos = Delete(pos->element, pos);	//删除当前元素，返回当前元素的下一元素位置
		}
		else						//未达加分要求，向后面的第一第二个元素之间插入新元素
		{
			pos = pos->Next;		//向后移一位
			if (pos->element == -1) //到头节点再移一位
				pos = pos->Next;
			pos = Insert(i, pos);	//在当前元素之后插入
		}
	}

	for (int i = 0; i < SIZE-1; ++i) //选择数组中最大的元素，放在最后
	{
		if (person[i] > person[i + 1])
			swap(person[i], person[i + 1]);
	}
	PtrtoNode p = header;
	while (header->Next != header)//释放双向循环链表
	{
		PtrtoNode tmp;
		tmp = p->Next;
		p->Next = tmp->Next;
		tmp->Next->Prior = p;
		tmp->Next = tmp->Prior = NULL;
		free(tmp);
		//tmp->Next = tmp->Prior = NULL;
	}
	printf("Answer: %u\n", person[SIZE-1]);
}
