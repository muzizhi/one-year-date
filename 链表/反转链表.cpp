//206、反转链表：反转一个链表注意尾指针null。要求递归或者迭代
//思路：之前做过一个移动链表是先成环再断。要求递归那么，1-2 2->1;1->null;1是递归项，但是1咋表示多一个少一个？那就是1-2-3:2,2’->1,1->null;然后是 3
// fan zhuan e xin


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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(head!=NULL)
        {
            ListNode *temp=head->next; //保留原来的链表
            cur->next=pre;// 反转 关系
            pre= cur;  //保存转换好的
            cur=temp;
            head= temp; //next while
        }
        return pre;
    }
};

/*
灰常容易弄晕，官方解答
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

*/
