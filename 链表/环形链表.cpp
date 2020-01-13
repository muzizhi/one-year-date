//141、环形链表：判断一个链表是否是环形链表，如果尾指针指向已搜索元素true(pose!=-1)
//思路：存储每个链表对应的pos是第几个，如果连接的下一个<pos，成环。怎么存pos？或者改为标记，看看是否走过该点。都很难写，listnode.flag/.pos没法定义。
//官方：快慢指针可能会比较慢，时间o（n）空间o1；哈希表更慢，存储已有的，时空o（n）；

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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return false;
        ListNode *fast=head->next->next;
        ListNode *slow=head->next;
        //链表长度怎么求解 &&双指针尝试
        while(fast!=slow)
        {
            if(fast==NULL||fast->next==NULL)
            return false;
            fast=fast->next->next;
            slow=slow->next;
        }
        return true;
    }
};

/*
给定标定，看看走过吗，java代码
var hasCycle = function(head) {
    while(head && head.next){
        if(head.flag){
            return true;
        }else{
            head.flag = 1;
            head = head.next;
        }
    }
    return false;
};

快慢指针：
快指针 和 慢指针 一定会进入环，无论快慢指针何时进入环，中间相隔任意个节点，总会在某一次移动后相遇， fast == slow 时候返回 1
C++ 代码如下 仅供参考

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL) {
        if (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            return 0;
        }
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

*/
