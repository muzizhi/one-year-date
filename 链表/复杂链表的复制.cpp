25、复杂链表的复制：一个节点两个指针，一个next，一个随机/null，全部复制下来
思路：关注节点定义，直接复制所有报错，浅拷贝还是原地址。
官方1:利用hashmap存储旧/新，返回map（head），新的值存储/然后next和random复制，p[t]->next=mp[t->next]，同样random返回。 
官方2:原链表修改，在后面复制一个值相同的，然后复制random，表示cur.next.random = cur.random.next;（两个相同要后面），然后分开两个链表。


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
//hashmap 存储实现
    Node* copyRandomList(Node* head) {
        if(head==NULL)  return head;
        unordered_map<Node*,Node*>mp;
        Node *t=head;
        while(t!=NULL){
            mp[t]=new Node(t->val);
            t=t->next;
        }
        t=head;
        while(t!=NULL){
            if(t->next){
                mp[t]->next=mp[t->next];
            }
            if(t->random){
                mp[t]->random=mp[t->random];
            }
            t=t->next;
        }
        return mp[head];
    }

};

/*
//hashmap 存储的，迭代实现
    Node* copyRandomList(Node* node) {
        if (node == nullptr) return nullptr;
        if (mp.count(node)) return mp[node]; //已创建过该节点

        Node* ans = new Node(node->val);
        mp[node] = ans; //老节点和新节点映射
        ans->next = copyRandomList(node->next);
        ans->random = copyRandomList(node->random);
        return ans;
    }
思路2:
原地修改解法流程：
复制一个新的节点在原有节点之后，如 1 -> 2 -> 3 -> null 复制完就是 1 -> 1 -> 2 -> 2 -> 3 - > 3 -> null
从头开始遍历链表，通过 cur.next.random = cur.random.next 可以将复制节点的随机指针串起来，当然需要判断 cur.random 是否存在
将复制完的链表一分为二 
*/
