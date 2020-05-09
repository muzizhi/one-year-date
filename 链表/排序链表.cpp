148、排序链表：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
思路：感觉2分？链表咋弄；官方：归并排序思路，很难理解。目前就是对于同级划分，确定一个h1/h2，合并，然后while继续，到这一层结束，然后下一层。
重点不利用递归的cut先完全划分，变成挨个分级合并，难点主要是确定每级要合的h1/h2，指针很乱；

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
    ListNode* sortList(ListNode* head) { //看懂思路和代码尝试
        if(!head) return NULL;
        //指针， res=head？没法换顺序;next 就能换了 因为head变了
        ListNode *res=new ListNode(0);
        res->next=head; 
        ListNode *cur=head,*h1,*h2,*pre;
        int len=0,size=1,size1,size2;
        while(cur){ // list length
            len++; cur=cur->next;
        }
        while(size<len){ //分层归并排序
            pre=res; //每层正确的值
            //cur=head; //回归尝试，也对
            cur=res->next; //回归   肯定正确的目前的回归结果
            while(cur){
                size1=size,size2=size;
                h1=cur; //
                while(size1){
                    //size1--;cur=cur->next;
                    if(cur) cur=cur->next;
                    else break;
                    size1--; //放后面，如果是5个，2轮可能前面的已经不够了
                }
                if(size1!=0) break; //第2轮 2 2 1, 1不需要比
                h2=cur; //
                while(size2){
                    if(cur) cur=cur->next;
                    else break;
                    size2--; //放后面，break 为满的
                }
                size1=size,size2= size-size2;
                cout<<"size="<<size<<"size1="<<size1<<"size2="<<size2<<endl;
                //合并开始
                while(size1&&size2){
                    if(h1->val<=h2->val){
                        pre->next=h1;
                        h1=h1->next;
                        size1--;
                    }
                    else{
                        pre->next=h2;
                        h2=h2->next;
                        size2--;
                    }
                    pre=pre->next; //每次都很容易忘记这个
                }
                //if(size1){ 不行，这样pre没法承接到后面，一直要在末尾
                //    pre->next=h1;}
                while(size1){
                    pre->next=h1;
                    h1=h1->next;
                    pre=pre->next;
                    size1--;
                }
                while(size2){
                    pre->next=h2;
                    h2=h2->next;
                    pre=pre->next;
                    size2--;
                }
                pre->next=cur; //感觉不需要，还要连接到后面继续的part，如果后面不合并呢
            }
            size=size*2;
        }
        return res->next;
    }
};

/* 参考评论1
疯狂苦学：归并排序 

不利用递归的cut，划分就是1个个/*2个个  这样挨个进行划分，真的有点难，看了好久，主要是确定h1/h2
研究1个小时，所以目前就是对于同级划分，确定一个h1/h2，合并，然后while继续，到这一层结束。


额外的归并排序，利用递归的，很好理解，但是本题不能用，因为递归有额外的空间o（logn）
思路就是：先分两份（快慢指针中点） 然后递归l 和r ，直到cut部分head-》next=null 单节点
合并就是 左和右比较，自身都排好顺序，每个合并后从小到大；
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode fast = head.next, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode tmp = slow.next;
        slow.next = null;
        ListNode left = sortList(head);
        ListNode right = sortList(tmp);
        ListNode h = new ListNode(0);
        ListNode res = h;
        while (left != null && right != null) {
            if (left.val < right.val) {
                h.next = left;
                left = left.next;
            } else {
                h.next = right;
                right = right.next;
            }
            h = h.next;
        }
        h.next = left != null ? left : right;
        return res.next;
    }
}


*/
