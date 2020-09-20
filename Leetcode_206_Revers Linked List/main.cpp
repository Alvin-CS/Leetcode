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
#include "list.h"



LinkList ReverseList(LinkList head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	ListNode *PreNode = head;
	ListNode *CurNode = head->next;
	head->next = NULL;
	ListNode *NextNode = CurNode->next;
    
	while (NextNode != NULL)
	{
		CurNode->next = PreNode;
		PreNode = CurNode;
		CurNode = NextNode;
		NextNode = CurNode->next;
	}

	CurNode->next = PreNode;
	head = CurNode;

	return head;
}


int main()
{
	LinkList OriginalList = InitList(5);
	DisplayList(OriginalList);
	LinkList ResultList = ReverseList(OriginalList);
	DisplayList(ResultList);

	return 0;
}