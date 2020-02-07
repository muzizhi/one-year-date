//234、回文链表：判断一个链表是否是回文链表，要求时间o（n），空间o（1）。
//思路：直接全部逆序，看看一样不。这样要扫描两遍，时间o（n），空间o（n），不可。用栈空间也不对，虽然一遍扫描。
//官方思路：需要到一半时候检查（快慢指针）慢指针刚好一半，然后逆序后面，挨个比较。

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        ListNode *pre=NULL;
        if(!head) return true;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<slow->val;
        while(slow) //reverse the mid-final
        {
            ListNode *temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;
        }
        while(pre)
        {
            cout<<pre->val<<endl;
            if(pre&& head &&pre->val!=head->val)
            //if(pre->val!=head->val)
                return false;
            if(pre) pre=pre->next;
            if(head) head=head->next;
        }
        return true;
    }
};

//快慢指针 找中点 一个跑到结尾，一个刚刚好 中点 ，然后在链表本身上翻转
//反复报错，气死（空的true、 0，0） 加了最后一部分

//直接全部逆序，看看一样不。这样需要扫描两遍，时间o（n），空间也是o（n），不可
//用栈，很合适，但是空间存储也有问题，虽然也是一遍遍历
