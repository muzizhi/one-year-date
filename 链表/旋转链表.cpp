//61、旋转链表：给出一个链表和一个数k，整体链表右移动k值。
//思路：求出链表长度n，要不然就是求一个新链表，每个值是对应原链表的x位置。「要判断跨界点的地方，前后不一样」
//要不然就是原链表上面，先连成环，然后修改新的首尾值，输出新的head值（n-k%n），更简单一点。

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
    ListNode* rotateRight(ListNode* head, int k) {
       // ListNode *rotate=new ListNode();
        ListNode *rotate=NULL;
        if(head==NULL) return rotate;
        ListNode *t=head;
        int n=1;// 返回链表长度貌似要 自己写
        while(t->next!=NULL)
        {
            t=t->next;
            n++;
        }
        t->next=head;  //circle create 1->2->3->4->5-> 1 
        int m=n-k%n;
        cout<<n<<m<<endl;
        while(m!=1)
        {
            head=head->next;
            m--;
        }
        rotate=head->next;// rotata->next=4
        head->next=NULL;// 3->next=null;
        return rotate;
    }
};

/*
方法一:截断性连接
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p=head,*t=head;
        int hsize=0;
        while(p!=NULL){
            p=p->next;
            hsize++;
        }
        if(hsize==0||k%hsize==0) return head; 
        int m=hsize-k%hsize-1,n=k%hsize-1;
        while(m-->0) head=head->next;
        ListNode* tp=head->next,*res=tp; //eg 1->2->3->4->5->NULL, k = 2, tp记录4->5->NULL
        head->next=NULL; //作用：1->2->3->NULL
        while(n-->0) tp=tp->next; //找到5
        tp->next=t; //作用：将5连到1, 4->5->1->2->3->NULL
        return res;
    }
};
方法二:设立一个头指针和尾指针，遍历一次链表得到链表的长度l。并将尾指针的next指向头指针，同时将head指针和尾指针向后移动L-k个元素，返回新head ，我的方案

*/
