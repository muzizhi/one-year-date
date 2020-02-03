//160、相交链表：找到两个单链表a，b相交的部分，输出相交第一个节点。
//思路：暴力法，直接挨个找是否相等。啊啊啊啊好难.
//官方思路：双指针拼接链表amazing。a+b前+相交=b+a前+相交=a+b长度。所以第一个相等就是相交处，太强了。
//另一种比较好想的（我都没想）求长度，计算长度差，先遍历长的链表，等长时，开始同时遍历两个链表，比较。相等则返回结点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        if(!a||!b) return NULL;
        while(a!=b)
        {
            a=  a==NULL?headB:a->next;
            b=  b==NULL?headA:b->next;
        }
        return a;
        //if(a) return a;
        //else return NULL; //a and b ==null
    }
};

//太强了整体的，双指针拼接思路
