460、LRU缓存：get和put函数，删除机制为使用频率 ，同频率删除最久使用的
思路：这个就还要考虑次数，旧的可能也不删。两个hash表，一个记录次数，一个原来的key记录时间。然后get就是找key，更新count；put更新key和count，好复杂。 
但是不用定义双链表了，因为只用删除和前面放入。


struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table; //不懂，迭代器咋了 优化
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();  //why clear，不用定义双链表吗
        freq_table.clear();
    }
    /*
    private:
    unordered_map<int,DLinkedNode*> key_table;  //定义旧的hash，存时间相关
    unordered_map<int,DLinkedNode*> freq_table;  //定义新的hash，存出现次数
    int minFreq;
public:
    LRUCache(int capacity):size(0) { //撑不下去了，这个双链接写法，两个head吗，咋写
        minFreq=0;
    }*/
    
    int get(int key) {
        //如果没有-1,有就要
        if(capacity==0) return -1;
        if(key_table.count(key)){
            list<Node>::iterator node=key_table[key]; //利用hash的快速查找
            int value=node->val,freq=node->freq;
            freq_table[freq].erase(node);
            // 如果当前链表为空，我们需要在次数哈希表中删除，且更新minFreq
            if(freq_table[freq].size()==0){
                freq_table.erase(freq);
                if(minfreq==freq) minfreq+=1;
            }
            // 插入到 freq + 1 中,放最前面，时间优先
            freq_table[freq+1].push_front(Node(key, value, freq + 1));
            //key_table[key]->freq=freq+1;  不能这么写不知道为啥，总之必须全部赋值
            key_table[key] = freq_table[freq + 1].begin();
            return value;
        }
        else return -1;

    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        //如果不在，添加
        if(!key_table.count(key)){
            if(key_table.size()==capacity){
                //int temp=freq_table[minfreq].back()->key// back is the final one
                //key_table.erase(temp);
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq); //min 先不要换，加完下面肯定是1
                }
            }
            freq_table[1].push_front(Node(key,value,1));
            minfreq=1;
            key_table[key]=freq_table[1].begin();
        }
        else{// 在就换个值，然后更新count
            list<Node>::iterator node=key_table[key]; //利用hash的快速查找
            int freq=node->freq;
            freq_table[freq].erase(node);
            // 如果当前链表为空，我们需要在次数哈希表中删除，且更新minFreq
            if(freq_table[freq].size()==0){
                freq_table.erase(freq);
                if(minfreq==freq) minfreq+=1;
            }
            // 插入到 freq + 1 中,放最前面，时间优先
            freq_table[freq+1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }

    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 /* 
还是哈希双链表,规则不一样 按照使用频率排序，所以旧的不一定在后面；count数组？记录次数？
问题： （1）怎么比较count 数组？--hash存储对应count
（2） 同频率还要比较最远使用，双链表存什么呢 - 两个分开
（3） 对应的 get/put怎么弄 -更新注意count换到count+1
看了官方解答，其心险恶。用两个hash表，一个记录count，一个记录原来的key记录时间。
知识点：
//从前面向listOne容器中添加数据
    listOne.push_front (2);
//从后面向listOne容器中添加数据
    listOne.push_back (3);
// back is the final one
    freq_table[minfreq].back();
*/
