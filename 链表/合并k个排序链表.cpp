23、合并k个排序链表：k个排序链表，返回合并结果，时间复杂度
思路：有点麻烦，每行都要比较，官方说可以用最优队列（小根堆）实现第一元素的比较，复杂度o(kn logk)；
官方思路2:会2个的，所以优化可以分治，2个排序，组成最后结果，复杂度一样。 
简直莫名其妙/分治一直错/不应该错/不懂



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next=NULL;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
   
class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {   //明明确实没有错误
        ListNode* res=new ListNode(0); 
        ListNode *l1=a,*l2=b,*l3=res;  
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1!=NULL&& l2!=NULL){
            if(l1->val  < l2->val){   //奇怪为啥报错,没有道理,折腾1h不知道
                l3->next=l1;
                l1=l1->next;
                l3=l3->next;
            }
            else{
                l3->next=l2;
                l2=l2->next;
                l3=l3->next;
            }
        }
        if(l1==NULL) l3->next=l2;
        if(l2==NULL) l3->next=l1;
        return res->next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};


/*  cuo
public:
    //分支方法的最好理解的版本，递归    （迭代就很emmm）
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        if(n==2) return mergetwoLists(lists[0],lists[1]);
        //每次更新总链表长度，然后两个一组
        while(n>1){
            int index=0;
            for(int i=0;i<n;i=i+2){
                if(i==n-1) //no lists[i+1]
                    lists[index++]=lists[n-1];
                lists[index++]=mergetwoLists(lists[i],lists[i+1]);

            }
            n=index;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {   //明明确实没有错误
        ListNode* res=new ListNode(0); 
        ListNode *l1=a,*l2=b,*l3=res;  
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1!=NULL&& l2!=NULL){
            if(l1->val  < l2->val){   //奇怪为啥报错,没有道理,折腾1h不知道
                l3->next=l1;
                l1=l1->next;
                l3=l3->next;
            }
            else{
                l3->next=l2;
                l2=l2->next;
                l3=l3->next;
            }
        }
        if(l1==NULL) l3->next=l2;
        if(l2==NULL) l3->next=l1;
        return res->next;
    }   
};   */

/*
还是老思路吗，比较每一个链表的开头，看看哪个放进去，然后指向next比较，优化思路：比较利用小根堆快速获取最小/不会写

还有一个官方思路，知道两个怎么成了，所以可以用顺序挨个ans和链表 o（k*K* n)
优化就是分治 两个两个合并，然后在调用。o(kn lok )  实现主要是怎么分/merge=mid ，merge2 （merge， merge）




*/
