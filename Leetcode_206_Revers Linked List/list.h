#include<stdio.h>

typedef int ElemType;

typedef struct ListNode {
	int val;
	struct ListNode* next;
}*LinkList;


LinkList InitList(int length);
void DisplayList(LinkList head);

