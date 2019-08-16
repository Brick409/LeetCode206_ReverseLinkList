
// ReverseLinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

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
	/* 通过设立4个指针的方式，分别指向小于x的结点组成的链表，大于X的节点的链表 */
	ListNode* partition(ListNode* head, int x) {
		//新建一个链表节点，用于存储大于X值的链表节点
		//NEW结构体必须初始化

		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode *smallHeadNode = NULL; //指向小于X的节点组成的链表的首节点
		ListNode *smallTailNode = NULL; //指向小于X的节点组成的链表的尾节点
		ListNode *bigHeadNode = NULL; //指向大于X的节点组成的链表的首节点
		ListNode *bigTailNode = NULL; //指向大于X的节点组成的链表的尾节点

		ListNode *curNode = head;  //当前待处理的节点

		while (curNode != NULL)
		{
			//当前节点的值大于X，然后将该节点挂在temp结点对应链表之后
			if (curNode->val < x)
			{
				if (NULL == smallTailNode)
				{
					smallHeadNode = curNode;
					smallTailNode = curNode;
				}
				else
				{
					smallTailNode->next = curNode;
					smallTailNode = curNode;
				}

			}
			else
			{
				if (NULL == bigTailNode)
				{
					bigHeadNode = curNode;
					bigTailNode = curNode;
				}
				else
				{
					bigTailNode->next = curNode;
					bigTailNode = curNode;
				}
			}

			curNode = curNode->next;
		}

		//针对原链表中数值均大于x的情况
		if (NULL == smallHeadNode)
		{
			return bigHeadNode;
		}
		//针对原链表中数值均小于x的情况
		if (NULL == bigHeadNode)
		{
			return smallHeadNode;
		}

		smallTailNode->next = bigHeadNode;

		bigTailNode->next = NULL;

		return smallHeadNode;
	}

	/* 以下算法超时，具体原因不清楚 */
	ListNode* partition1(ListNode* head, int x) {
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
				preNode->next = curNode->next;

				newNode = curNode;
				curNode = curNode->next;
		
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
	/*
	328题目：
	给出一个链表，将链表重新整理，使得所有索引为奇数的节点排在所因为偶数的节点前面；
	*/
	ListNode* oddEvenList(ListNode* head) {
		ListNode *oddCur = head;  //当前奇数节点

		ListNode *evenTempHead = NULL; //用作临时节点，存放偶数节点的头节点

		ListNode *evenCur = NULL; //当前偶数节点


		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		evenTempHead = head->next;
		evenCur = head->next;

		//注意以下逻辑判断，evenCur结点至少为倒数第二个节点，再进行处理

		while (evenCur != NULL && evenCur->next != NULL)
		{
			oddCur->next = oddCur->next->next;
			evenCur->next = evenCur->next->next;

			oddCur = oddCur->next;
			evenCur = evenCur->next;
		}

		oddCur->next = evenTempHead;

		return head;
	}
	/*
	链表问题：一般设立链表的虚拟头节点方便解题

	203号问题：
	在链表中删除指定结点，即值为val的节点。
	Input:  1->2->6->3->4->5->6, val = 6
	Output: 1->2->3->4->5
	*/

	ListNode* removeElements(ListNode* head, int val) {
		
		ListNode *curNode = head;
		ListNode *preNode = head;

		if (head==NULL)
		{
			return head;
		}

		//针对待处理的一个结点等于val的场景特殊处理

		while (head!=NULL && head->val==val)
		{
			head = head->next;
		}

		while (curNode!=NULL)
		{
			if (curNode->val == val)
			{
				preNode->next = curNode->next;	
			}
			else
			{
				preNode = curNode;
			}
			curNode = curNode->next;

		}


		return head;

	}
	/*
	445号问题：
	给出两个非空链表，表示两个非负整数。其中每一个整数的各位数字以逆序存储，返回这两个整数相加所代表的链表。
	Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 8 -> 0 -> 7
	*/

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		/*
		使用两个栈来辅助运算。
		*/
		stack<int> s1, s2;
		//将L1中数据存入S1，L2中数据存入S2
		while (l1!=NULL)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}

		while (l2!=NULL)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}

		int carry = 0; //表示相加的进位数
		int numSum = 0; //临时存放两个结点中数字之和

		//循环条件为进位非空、S1栈非空、S2栈非空
		while (carry || (!s1.empty()) || (!s2.empty()))
		{
			numSum = carry;
			
			if (!s1.empty())
			{
				numSum += s1.top();
				s1.pop();
			}

			if (!s2.empty())
			{
				numSum += s2.top();
				s2.pop();
			}

			

		}



	}
};



int _tmain(int argc, _TCHAR* argv[])
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    int arr2[] = { 1, 4, 6, 3, 6, 2, 5, 2 };

	int x = 6;

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

	//ListNode * printHead = Solution().removeElements(pHead2, x);




	printLinkList(printHead);

    system("pause");

	return 0;
}

