40、数组中出现一次的数字：数组其他两次，只有两个出现了一次。空间o（n）/o1
思路：不太一样，一个直接异或得到值。用hash存储结果，最后输出1次的。异或可行，第一遍获取两个数异或结果，然后找到res1第几位。将其他数进行区分，两类重新异或。

class Solution {
public:
    vector<int> singleNumbers(vector<int>& data) {
        unordered_map<int,int> hash;
        for(int k: data){
            hash[k]++;
            //cout<<hash[k];
        }
        vector<int> res;
        for(int k:data){
            if(hash[k]==1)
                res.push_back(k);
        }
        return res;
    }
};

//要不然设置 hash数组，然后存储对应上的2，无1， 然后输出1的那两个
//空间高,其他思路
/*
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }

*/思路：不太一样，一个直接异或得到值。用hash存储结果，最后输出1次的。异或可行，第一遍获取两个数异或结果，然后找到res1第几位。将其他数进行区分，两类重新异或。
