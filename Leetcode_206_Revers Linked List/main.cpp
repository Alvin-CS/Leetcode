/*

206. Reverse Linked List

Descriptioin:

	Reverse a singly linked list.

Example:

	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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