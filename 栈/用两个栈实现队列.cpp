面试9:用两个栈实现队列：实现队尾插入，队头删除（同时返回删除值）的两个功能
思路：1栈底是队列头，头删除（从1到2，2pop，再到1）；尾插入（1push），成功


class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
        
    CQueue() {
        int size=0;
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    //返回 要删除的元素/-1
    int deleteHead() {
        if(stack1.empty()){
            return -1;
        }
        while(!stack1.empty()){  //从1到2，2pop
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res=stack2.top();
        stack2.pop();
        while(!stack2.empty()){ //再到1
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;

    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

 /*
自己：1栈底是队列头，头删除（从1到2，2pop，再到1）；尾插入（1push）

官方：1栈顶是对头，头删除（1pop）；尾插入（从1到2，1push，再到1）
维护队列的元素个数，插入个数加 1。删除减 1。
 */
