
// ReverseLinkList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/* ʵ������ת */
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//ͨ��һ�����鴴��һ������,����nΪ��Ҫ����������ڵ����
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

//��ӡһ�������ÿ���ڵ�
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

//ɾ������Ľڵ�
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

//����������ͬ�Ľڵ�ָ�룬��ת����
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
    /*83�����⣺
    ����һ����������ɾ�����������ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�*/
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

    /* ��֪��������head1 ��head2 �������򣨴�С���󣩣�
       ������Ǻϲ���һ��������Ȼ����(�������н�㣬�����С��ͬ��*/
    ListNode * mergeTwoList1(ListNode *head1,ListNode *head2)
    {
        ListNode *head = NULL;
        ListNode *pCurNode = NULL; //��ʾ���ڴ���ڵ�

        ListNode *p1 = NULL; //ָ������1���ȽϵĽڵ�
        ListNode *p2 = NULL; //ָ������2���ȽϵĽڵ�

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

        //��ǰ���Ƚ������ڵ�ǿ�
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
        ��֪��������head1 ��head2 ��������(��С����)��
        ������Ǻϲ���һ��������Ȼ�������Ҫ���õݹ鷽�����С�(Autodesk)
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
	86�����⣺
	����һ�������Լ�һ����X����������������ʹ��С��x��Ԫ����ǰ�����ڵ���x��Ԫ���ں�
	Input: head = 1->4->3->2->5->2, x = 3
	Output: 1->2->2->4->3->5
	*/
	ListNode* partition(ListNode* head, int x) {
		//�½�һ������ڵ㣬���ڴ洢����Xֵ������ڵ�
		//NEW�ṹ������ʼ��

		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		ListNode *tempNode = new ListNode(0);

		ListNode *newNode = tempNode; //ָ���������ĩβ�ڵ�

		ListNode *curNode = head; //��ǰ������Ľ��
		ListNode *preNode = head; //��ǰ������Ľ���ǰһ���ڵ�

		while (curNode != NULL)
		{
			//��ǰ�ڵ��ֵ����X��Ȼ�󽫸ýڵ����temp����Ӧ����֮��
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


328��Ŀ��
    ����һ��������������������ʹ����������Ϊ�����Ľڵ���������Ϊż���Ľڵ�ǰ�棻
2�����⣺
    ���������ɿ�������ʾ�����Ǹ�����������ÿһ�������ĸ�λ����������洢������������������������������

445��Ŀ��
*/

/*
�������⣺һ���������������ͷ�ڵ㷽�����

203�����⣺
    ��������ɾ��ֵΪval�Ľڵ㡣



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

