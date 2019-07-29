
// ReverseLinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/* 实现链表反转 */
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//通过一个数组创建一个链表,其中n为需要创建的链表节点个数
ListNode * CreatList(int arr[], int n)
{
    if (n == 0)
    {
        return NULL;
    }

    ListNode *head = new ListNode(arr[0]);
    
    ListNode *curNode = head;

    for (int i = 1; i < n; i++)
    {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;

}

//打印一个链表的每个节点
void printLinkList(ListNode *head)
{
    ListNode * cur = head;
    while (cur!=NULL)
    {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << NULL;
}

//删除链表的节点
void deleteListNode(ListNode *head)
{
    ListNode *curNode = head;

    while (curNode!=NULL)
    {
        ListNode *deleteNode = curNode;
        curNode = curNode->next;
        delete deleteNode;
    }
    return;
}

//定义三个不同的节点指针，反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;

        while (cur != NULL)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
    /*83号问题：
    给出一个有序链表，删除其中所有重复元素，使得每个元素只保留一次。*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pCur = NULL;
        ListNode *pNext = NULL;

        if (head==NULL|| head->next==NULL)
        {
            return head;
        }

        pCur = head;
        pNext = head->next;

        while (pNext!=NULL)
        {
            if (pNext->val > pCur->val)
            {
                pCur->next = pNext;
                pCur = pNext;
                pNext = pNext->next;
            }
            else
            {
                pNext = pNext->next;
                pCur->next = pNext;
            }
        }

        return head;
    }

    /* 已知两个链表head1 和head2 各自有序（从小到大），
       请把它们合并成一个链表依然有序。(保留所有结点，即便大小相同）*/
    ListNode * mergeTwoList1(ListNode *head1,ListNode *head2)
    {
        ListNode *head = NULL;
        ListNode *pCurNode = NULL; //表示正在处理节点

        ListNode *p1 = NULL; //指向链表1待比较的节点
        ListNode *p2 = NULL; //指向链表2待比较的节点

        if (head1==NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }

        if ((head1->val)<(head2->val))
        {
            head = head1;
            p1 = head1->next;
            p2 = head2;
        }
        else
        {
            head = head2;
            p1 = head1;
            p2 = head2->next;
        }

        pCurNode = head;

        //当前待比较两个节点非空
        while ((p1!=NULL)&&(p2!=NULL))
        {
            if ((p1->val) < (p2->val))
            {
                pCurNode->next = p1;
                pCurNode = p1;
                p1 = p1->next;
            } 
            else
            {
                pCurNode->next = p2;
                pCurNode = p2;
                p2 = p2->next;
            }
        }

        if (p1!=NULL)
        {
            pCurNode->next = p1;
        }

        if (p2 != NULL)
        {
            pCurNode->next = p2;
        }

        return head;
    }

    /*
        已知两个链表head1 和head2 各自有序(从小到大)，
        请把它们合并成一个链表依然有序，这次要求用递归方法进行。(Autodesk)
    */
    ListNode * mergeTwoList2(ListNode * head1, ListNode * head2)
    {
        ListNode *head = NULL;

        if (head1==NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }

        if (head1->val < head2->val)
        {
            head = head1;
            head->next = mergeTwoList2(head1->next, head2);
        }
        else
        {
            head = head2;
            head->next = mergeTwoList2(head1, head2->next);
        }

        return head;
    }
	/*
	86号问题：
	给出一个链表以及一个数X，将链表重新整理，使得小于x的元素在前；大于等于x的元素在后；
	Input: head = 1->4->3->2->5->2, x = 3
	Output: 1->2->2->4->3->5
	*/
	ListNode* partition(ListNode* head, int x) {
		//新建一个链表节点，用于存储大于X值的链表节点
		//NEW结构体必须初始化

		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		ListNode *tempNode = new ListNode(0);

		ListNode *newNode = tempNode; //指向新链表的末尾节点

		ListNode *curNode = head; //当前待处理的结点
		ListNode *preNode = head; //当前待处理的结点的前一个节点

		while (curNode != NULL)
		{
			//当前节点的值大于X，然后将该节点挂在temp结点对应链表之后
			if (curNode->val >= x)
			{
				newNode->next = curNode;
				newNode = curNode;
				curNode = curNode->next;
				preNode->next = curNode;
				preNode = preNode->next;
			}
			else
			{
				preNode = curNode;
				curNode = curNode->next;
			}
		}

		preNode->next = tempNode->next;

		newNode->next = NULL;

		delete[] tempNode;
		tempNode = NULL;

		return head;
	}

};

/*


328题目：
    给出一个链表，将链表重新整理，使得所有索引为奇数的节点排在所因为偶数的节点前面；
2号问题：
    给出两个飞控链表，表示两个非负整数。其中每一个整数的各位数字以逆序存储，返回这两个整数相加所代表的链表。

445题目：
*/

/*
链表问题：一般设立链表的虚拟头节点方便解题

203号问题：
    在链表中删除值为val的节点。



*/


int _tmain(int argc, _TCHAR* argv[])
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    int arr2[] = { 1, 4, 3, 2, 5, 2 };

	int x = 3;

    int n1 = sizeof(arr1) / sizeof(int);

    ListNode *pHead1 = CreatList(arr1, n1);


    int n2 = sizeof(arr2) / sizeof(int);

    ListNode *pHead2 = CreatList(arr2, n2);


    printLinkList(pHead1);

    cout << endl;


    printLinkList(pHead2);

    cout << endl;


    //ListNode *pCurAfterReverse = Solution().reverseList(pHead);

    //printLinkList(pCurAfterReverse);

    //deleteListNode(pCurAfterReverse);


    //ListNode * mergeHead = Solution().mergeTwoList1(pHead1, pHead2);

    //printLinkList(mergeHead);

    //cout << endl;

    //ListNode * printHead = Solution().deleteDuplicates(mergeHead);

    //printLinkList(printHead);

	ListNode * printHead = Solution().partition(pHead2, x);

	printLinkList(printHead);

    system("pause");

	return 0;
}

