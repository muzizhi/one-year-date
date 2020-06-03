128、最长连续序列：未排序整数数组，返回最长连续序列长度，时间o（n）
思路：排序就超时了，没思路。从暴力法之中进行改善，利用哈希表实现快速搜索。找开头的数据（没有哈希表中比他小），然后记录长度，更新。



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int n:nums) hash[n]=1; //插入hash表
        int res=0,c=1;  //if 空就是res=0
        for(int i:nums){
            cout<<i<<endl;
            if(hash.count(i-1)){
                //不能做开头
                continue;
            }
            while(hash.count(i+1)){
                i++;
                c++; //这次多少钱
            }
            cout<<i<<endl;
            res=max(res,c);
            c=1; //差点忘记了
        }
        return res;
    }
};


/*
思路：从暴力法之中进行改善，利用哈希表实现快速搜索
找开头的数据（没有哈希表中比他小），然后记录长度，更新  
*/
