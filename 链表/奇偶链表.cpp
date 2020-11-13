328、奇偶链表：奇数和偶数节点分别连接，然后奇数组后面连上偶数组构成链表。原地
思路：要求一趟遍历原地输出。设一个奇数头j，一个偶数头o，然后next=head-》next，最后奇数-〉next=偶数头，try/wrong o和j 会改变head，不能引入head。
官方思路：不用head，直接j和o关系，j->next=o->next;j=j->next;-- o->next=j->next;o=o->next;完美

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* j=head;
        ListNode* o=head->next;
        ListNode* temp=o;
        while(j && o && o->next){  //一定注意o-》next，否则第三句wrong；and 不需要加null
            j->next=o->next;
            j=j->next;  //时刻关注链表的波动
            o->next=j->next;
            o=o->next; //from 1 2 to 3 4
        }
        j->next=temp;
        return head;
    }
};

//有点难搞，一个奇数头，一个偶数头，然后next=next-》next，然后奇数-〉next=偶数头，尝试
// 果然错误，o和j 会改变head，不能引入head。懂了官方让j和o之间转换
