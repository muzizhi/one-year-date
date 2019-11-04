//两数之和π：链表存储，数字最高位在头节点（正序），不能翻转链表。(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)=7 -> 8 -> 0 -> 7。（7243+564=7807）
//搜索的时候存储数字，然后相加再输出，如何把数输出为链表：数字转字符串，字符串逐个输出。「整数long long 都不行」
//换种方式，只好用数组定义数字加法，或者用字符串定义大整数加法。
//别人的思路：递归算法，或者遍历两个链表，将指向节点的指针存入两个栈中。从栈顶开始取节点的值求和。每求出一对节点的和，出栈节点。直到两栈都为空


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3= new ListNode(0);
        ListNode* p=l3;
        string a,b,c;
        while(l1!=NULL || l2!=NULL)  //输出l1和l2对应字符串形式,可分开while
        {
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            if(l1!=NULL)  //完结之后就不要空补0
            {
                a=a+to_string(x);
                l1=l1->next; //放非空判断里面
            }
            if(l2!=NULL)
            {
                b=b+to_string(y);
                l2=l2->next;
            }
        }
        //大整数加法,字符串不需要倒叙，直接都是末位加和就好
        int count=0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0)
        {           
            //int sum=a[i]-'0'+b[j]-"0"+count; i，j可能小0
            int sum=0;
            if(i>=0)sum=a[i]-'0';
            if(j>=0)sum=sum+b[j]-'0';
            sum=sum+count;
            count = sum/10;  //不用分sum是否 超过10
            c.insert(0,1,(sum%10+'0'));
            i--;j--;
        }
        if(count!=0) c.insert(0,1,count+'0');
        //字符串c成链表输出
        for(int i=0;i<c.size();i++)
        {
            int temp=c[i]-'0';
            p->next=new ListNode(temp); 
            p=p->next;
        }
        return l3->next;
    }
};

//别人的思路有：先把链表长度补整齐，然后用递归算法。递归到最后一个再挨个回溯
//用两个栈 vector定义
/*
法一：递归
void addLinkList(struct ListNode* l1, struct ListNode* l2,int *cout)
{       
        if(l1==NULL||l2==NULL)
            return;
        if(l1->next!=NULL&&l2->next!=NULL)
            addLinkList(l1->next,l2->next,cout);
        int Sum=l1->val+l2->val+*cout;
        if(Sum>=10)
        {
            *cout=1;
            l1->val=Sum%10;
        }
        else
        {
            *cout=0;
            l1->val=Sum;
        }
        return;
}
失败的整数直接加法（大整数溢出,整数定义long long 还是超过了，直接加失败）
法二、双栈
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> l1v,l2v;
        to_vector(l1,l1v);
        to_vector(l2,l2v);
        int i=l1v.size()-1, j=l2v.size()-1;
        int d = 0;
        ListNode *head = NULL;
        while(i >= 0 || j >= 0){
            if(i >= 0) d += l1v[i--]->val;
            if(j >= 0) d += l2v[j--]->val;
            ListNode* p = new ListNode(d%10);
            p->next = head;
            head = p;
            d /= 10;
        }
        if(d) {
            ListNode* p = new ListNode(d);
            p->next = head;
            head = p;
        }
        return head;
    }
    
    void to_vector(ListNode* a,vector<ListNode*>& v){
        while(a){
            v.push_back(a);
            a = a->next;
        }
    }

*/
