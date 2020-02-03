//155、最小栈：设计一个函数功能push、pop、top、o（1）时间寻找最小栈元素
//思路：主要考察最小栈元素？常数时间寻找？-遍历一遍就是on，哈希也不合适。
//官方较好的思路：两个栈结构，a日常数据，b栈顶存最小。如果入栈比它小，则b入栈。否则不入，如果出栈元素与栈顶一致，那么b出栈。

//设计栈结构迷茫：如果不直接用栈结构，考虑链表结构。
//cool直接用一个链表即可实现栈的基本功能，那么最小值：我们可以在 Node 节点中增加一个 min 字段，输出head.min。重点是链表push是倒着

class MinStack { //利用辅助栈，写一波 -- 有点取巧，之后要练习链表
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if(min.empty()|| x<=min.top())//如果进来一个小的或相等，保留 | no.1
        {
            min.push(x);
        }
    }
    
    void pop() {
       // data.pop();
        if(data.top()==min.top()) //相等当前最小值  丢弃
        {
            min.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 /* 不直接用栈结构，考虑用链表结构来 实现栈的功能，定义真的很棒呀。
 class MinStack {
    class Node{
        int value;
        int min;
        Node next;

        Node(int x, int min){
            this.value=x;
            this.min=min;
            next = null;
        }
    }
    Node head;
//每次加入的节点放到头部 队列是 n n-1 3 2 no.1元素
    public void push(int x) {
        if(null==head){
            head = new Node(x,x);
        }else{
            //当前值和之前头结点的最小值较小的做为当前的 min
            Node n = new Node(x, Math.min(x,head.min));
            n.next=head;
            head=n;
        }
    }
//去掉head
    public void pop() {
        if(head!=null)
            head =head.next;
    }
//输出head。value
    public int top() {
        if(head!=null)
            return head.value;
        return -1;
    }
//输出head。min
    public int getMin() {
        if(null!=head)
            return head.min;
        return -1;
    }
}
 */
