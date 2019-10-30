//两数相加：链表逆序存储，(2 -> 4 -> 3) + (5 -> 6 -> 4) =7 -> 0 -> 8（342 + 465 = 807）
//思路：定义链表对应位置相加，定义进位，注意最后链表都空，进位1输出


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} //这个是赋值运算吗
 * };
 */
class Solution { //极度不娴熟定义
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count=0;
        ListNode *l3= new ListNode(0); //尝试初始化定义链表
        ListNode *p=l1,*q=l2,*t =l3;  //定义链表的头指针
        //while(*p!=NULL || *q!=NULL)
        //while(p!=NULL || q!=NULL) //错误，最后一个全空有carry位
        while(p!=NULL || q!=NULL )
        {
            //t=p+q+count;
            int x=(p!=NULL)?p->val:0;
            int y=(q!=NULL)?q->val:0;
            int sum=x+y+count;
            if(sum>=10)
            {
                count=1;
                sum=sum-10;
            }
            else count=0;
            t->next= new ListNode(sum);    //值传递给l3 链表
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
            t=t->next;
        }
        if(count!=0)
            t->next= new ListNode(count);
        return l3->next;  //返回值也要注意
    }
};
