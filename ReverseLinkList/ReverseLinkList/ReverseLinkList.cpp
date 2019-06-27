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

//����������ͬ�Ľڵ�ָ��
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
};

/*
83�����⣺
    ����һ����������ɾ�����������ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ��

86�����⣺
    ����һ�������Լ�һ����X����������������ʹ��С��x��Ԫ����ǰ�����ڵ���x��Ԫ���ں�

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
    int arr[] = { 1, 2, 3, 4, 5 };

    int n = sizeof(arr) / sizeof(int);

    ListNode *pHead = CreatList(arr, n);
    printLinkList(pHead);
    cout << endl;
    ListNode *pCurAfterReverse = Solution().reverseList(pHead);
    printLinkList(pCurAfterReverse);

    deleteListNode(pCurAfterReverse);

    system("pause");

	return 0;
}

