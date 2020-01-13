//142、环形链表2:不改变链表，如果是环形链表，返回进行环形对应的节点（pos）。
//思路：感觉存储数据的只能哈希表上。哈希存对应节点

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        unordered_map<ListNode*,int> hash;
        while(head->next!=NULL)
        {
            if(hash.count(head))
            {
                return head; //自动默认输出 pos=head对应值
            }
            else
            //hash.insert(head,1);
            hash[head]=1;
            head=head->next;
        }
        return NULL;
    }
};
