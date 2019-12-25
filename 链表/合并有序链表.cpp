//21、合并两个有序链表。按顺序排序链表，可重复数字
//思路：双指针，小的输出++，相同同时输出++，直到结束。剩余的没扫完直接输出
//或者采用递归，如果空，直接输出另一个，否则小的那个输出->next=递归其余值

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0);
        ListNode *q=l1,*p=l2,*t=l3; //定义头指针
        while(q!=NULL&&p!=NULL)
        {
            if(q->val==p->val)
            {
                t->next=new ListNode(q->val); //注意一下要用-》，并且原来可以直接t-〉next=q；
                //t->next=q;  超过时间限制了
                t->next->next=new ListNode(p->val);
                t=t->next->next;
                q=q->next; p=p->next;
            }
            else if(q->val>p->val)
            {
                t->next=new ListNode(p->val);
                t=t->next;
                p=p->next;
            }
            else
            {
                t->next=new ListNode(q->val);
                t=t->next;
                q=q->next; 
            }
        }
        if(p) t->next=p;
        if(q) t->next=q;
        return l3->next;
    }
};

/*
递归实现 public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

原来链表居然可以直接 赋值到指针。
        if(q->val>p->val)
            {
                r->next=p;
                r=r->next;
                p=p->next;
            }
      
*/
