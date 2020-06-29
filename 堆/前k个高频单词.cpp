692、前k个高频单词：一致，相同频字母排序，要求O(n log k) 时间和 O(n) 空间
思路：其他一样，这里的重点要求在重新定义 优先队列比较，设为频率+单词比较


class Solution {
public:
    //重点来了，queue比较加入单词
    struct cmp{
        bool operator()(pair<int,string> &a, pair<int,string> &b){
            if(a.first!=b.first){
                return a.first>b.first; 
            }
            else{
                return a.second<b.second;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        vector<string> res;// 存储结果
        //hash存频率
        for(auto num:words){
            if(hash.count(num)){
                hash[num]++;
            }
            else
                hash[num]=1;
        }
        //小跟堆保留 k大
        using pa= std::pair<int,string>;
        //priority_queue<pa,vector<pa>,greater<pa>> p; // 默认比较pair第一个的值，
        priority_queue<pa,vector<pa>,cmp> p; // 自定义比较
        for(auto &m: hash){
            p.push(std::pair<int,string>(m.second,m.first));
            if(p.size()>k) p.pop();
        }
        //输出结果进入res
        while(k--){
            res.push_back(p.top().second); //second is 元素
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};



/*
咋用到堆了呢，感觉如果排序直接统计个数，或者用hash表统计，感觉还不用排序了
重点是频率数组选最大k个，hash（num）=count？？
用小根堆，第二步建立堆，堆中添加一个元素的复杂度是 O(log(k))，要进行 N 次复杂度是O(N)。

*/
