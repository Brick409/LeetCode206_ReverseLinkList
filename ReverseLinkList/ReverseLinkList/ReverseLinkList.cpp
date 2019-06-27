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

//定义三个不同的节点指针
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
83号问题：
    给粗一个有序链表，删除其中所有重复元素，使得每个元素只保留一次

86号问题：
    给出一个链表以及一个数X，将链表重新整理，使得小于x的元素在前；大于等于x的元素在后；

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

