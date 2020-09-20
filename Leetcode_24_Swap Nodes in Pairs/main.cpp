/*

24. Swap Nodes in Pairs

Description：

	Given a linked list, swap every two adjacent nodes and return its head.

	You may not modify the values in the list's nodes, only nodes itself may be changed.

	给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

	你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


Example:

	Given 1->2->3->4, you should return the list as 2->1->4->3. 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LinkList SwapPairs(LinkList head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* CurNode = head;
	ListNode* NxtNode = head->next;
	ListNode* NxtArea = NxtNode->next;
	ListNode* PreArea = NULL;

	NxtNode->next = CurNode;
	CurNode->next = NxtArea;
	PreArea = CurNode;
	
	head = NxtNode;

	while (NxtArea)
	{	
		CurNode = NxtArea;
		NxtNode = CurNode->next;

		if (NxtNode)
		{
			NxtArea = NxtNode->next;

			NxtNode->next = CurNode;
			CurNode->next = NxtArea;
			
			PreArea->next = NxtNode;
			
			PreArea = CurNode;
		}
		else
		{
			NxtArea = NULL;
		}

	}


	return head;
}


int main()
{
	LinkList OriginalList = InitList(5);
	DisplayList(OriginalList);

	LinkList ResultList = SwapPairs(OriginalList);
	DisplayList(ResultList);

	return 0;
}







#if 0
int main()
{
	int a = 0;
	int b = 1;
	int* x = &a;
	int* y = &b;
	int* temp;

	temp = x;
	x = y;
	y = temp;
	printf_s("x = %d, y = %d \n", *x, *y);
	return 0;
}
#endif