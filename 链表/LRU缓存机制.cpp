146、LRU缓存机制：get和put函数，lru（最近最少使用）有容量上限，删除最久使用的
思路：哈希表不够，官方思路+双边链表（没用过）。get就是将节点移最前面，然后返回值/-1；put就是头加入值/移动最前面更新哈希值；
一个节点移到双向链表的头部，可以分成「删除该节点」和「在双向链表的头部添加节点」两步操作。具体实现参考官方。

//构建 哈希双链表数据类型
struct DLinkedNode{
    DLinkedNode *pre;
    DLinkedNode *next;
    int key,value;//  why keep both vulue,释放中需要key，返回需要value
    DLinkedNode(): key(0),value(0),pre(NULL),next(NULL){}
    DLinkedNode(int keyi,int valuei): key(keyi),value(valuei),pre(NULL),next(NULL){}
    // ListNode(int x) : value(x), next(NULL) {}
};

class LRUCache {
private:
    DLinkedNode *head;
    DLinkedNode *tail;
    unordered_map<int,DLinkedNode*> cache; 
    int size,cap;
public:
    LRUCache(int capacity):size(0) {
        cap=capacity; 
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        //如果有就返回，node移最前面
        if(cache.count(key)){
            DLinkedNode *node=cache[key]; //利用hash的快速查找
            moveToHead(node);
            return node->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        //如果没有添加前面，检查容量，删除最后一个
        if(!cache.count(key)){
            DLinkedNode *node=new DLinkedNode(key,value);
            addToHead(node);
            cache[key]=node;  //易错点，map更新插入新的映射
            size=cache.size();  //hash表的size 求解
            if(size>cap){
                DLinkedNode *node=removeTail();
                cache.erase(node->key); 
            }
        }
        //如果有，找到放前面，更新一下值
        else{
            DLinkedNode *node=cache[key];
            moveToHead(node);
            node->value=value;
        }
    }

    //基础的删除，添加操作 由链表实现
    void addToHead(DLinkedNode *node){
        node->pre=head;
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
    }
    void removeNode(DLinkedNode *node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }
    void moveToHead(DLinkedNode *node){
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode *removeTail(){
        DLinkedNode *node=tail->pre;
        removeNode(node);
        return node;  //用于删除对应map映射
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 /* 
用什么数据结构表示呢？哈希表？存一个对应一个  还需要有一个存远近的，参考官方-双边链表（没用过）
get就是将节点移最前面，然后返回值/-1；put就是头加入值/移动最前面更新哈希值；
一个节点移到双向链表的头部，可以分成「删除该节点」和「在双向链表的头部添加节点」两步操作
具体实现也有点恍惚
注意： （1）注意删除时候 也要删除对应的hash
（2）cache.erase(node->key); 
ListNode(int x) : value(x), next(NULL) {}
 */
