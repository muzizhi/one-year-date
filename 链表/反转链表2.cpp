//92、反转链表2:反转从m-n范围的链表，一趟扫描要求。
//思路：感觉应该是12 345 6，到3开始2保存，cur/pre逆序结束，2-pre；当pre空替换 6。注意m如果是头指针，要调整一下输出以及保留的2.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *cur,*pre=NULL;
        ListNode *temp,*t=head;
        if(!head) return head;
        for(int i=1;i<=n+1;i++) //i 最高到n+1 就足够了。
        {
            if(i<m-1)
            {
                t=t->next;
            }
            if(i==m-1)  //保留 1
            {
                temp=t;
                cout<<temp->val<<endl;;
                t=t->next;
            }
            if(i>=m&&i<=n)// reserve 234 -432
            {
                cur=t;
                t=t->next;
                cout<<cur->val<<endl;
                cur->next=pre;
                pre=cur;
                //t=t->next;
            }
            if(i==n+1)  //保留5 同时1-》4
            {
                if(m!=1) temp->next=pre; // 不知道咋了，必须m限定，temp不中
                else temp=pre;  //m is head
                cur=t;
                cout<<temp->val<<endl;
            }
        }
        while(pre->next!=NULL)
        {
            pre=pre->next;
        }
        pre->next=cur;  //2-》5

        if(m!=1) return head;
        else return temp;  // 考虑从头开始倒叙的
    }
};
//大致构思假如：12 345 6
//for到3 开始  2-3 3-null； 2-4 4-3； 2-5 5-4； 结束 pre5 -432-null/ 换6
