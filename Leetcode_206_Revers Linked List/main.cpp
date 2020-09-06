/*

206. Reverse Linked List

Descriptioin:

	Reverse a singly linked list.

Example:

	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NULL

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-linked-list/
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct ListNode {
	int val;
	struct ListNode* next;
}*LinkList;

LinkList InitList(int length)
{
	ListNode* head;
	head = (ListNode*)malloc(sizeof(ListNode));

	
	if (head == NULL)
	{
		printf_s("Memory Allocation Failed\n");
	}		
	else
	{
		head->val = 0;
		head->next = NULL;
		ListNode* op = head;
		for (int i = 1; i < length; i++)
		{
			ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
			tmp->val = i;

			tmp->next = op->next;
			op->next = tmp;
			op = tmp;
		}
	}
	return head;
}

void DisplayList(LinkList head)
{
	if (head == NULL)
		printf_s("The Linked List Is Empty\n");
	LinkList p = head;
	while (p)
	{
		printf_s("%d -> ", p->val);
		p = p->next;
	}
	printf_s("NULL\n");
}



int main()
{
	LinkList OriginalList = InitList(5);
	DisplayList(OriginalList);
}