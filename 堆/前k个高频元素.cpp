347、前k个高频元素：给k，返回重复数组出现频率前k高的数字，时间o（nlogn）
思路：先用哈希表存储值对应的频率，然后频率利用小根堆进行优化。理解就是限制为k个，>k时如果比顶频率值还小就不要了，那么留下来的是最大的k个。输出就可以了

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> res;// 存储结果
        //hash存频率
        for(auto num:nums){
            if(hash.count(num)){
                hash[num]++;
            }
            else
                hash[num]=1;
        }
        //小跟堆保留 k大
        using pa= std::pair<int,int>;
        priority_queue<pa,vector<pa>,greater<pa>> p;
        for(auto &pair: hash){
            //p.emplace(pair.second,pair.first); //对于pair的比较，貌似是比较第一个的值
            p.push(std::pair<int,int>(pair.second,pair.first));
            if(p.size()>k) p.pop();
        }
        //输出结果进入res
        while(k--){
            res.push_back(p.top().second); //second is 元素
            p.pop();
        }
        return res;
    }
};

/*
咋用到堆了呢，感觉如果排序直接统计个数，或者用hash表统计，感觉还不用排序了
重点是频率数组选最大k个，vector（num）=count， 如果排序num不对应，

用小根堆，第二步建立堆，堆中添加一个元素的复杂度是 O(log(k))，要进行 N 次复杂度是O(N)。
最后一步是输出结果，复杂度为 O(klog(k))。


*/
