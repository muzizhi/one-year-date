300、最长上升序列：无序的整数数组，找到其中最长上升子序列的长度
思路：这个可以维持数组，每个都找个小的替换，一遍慢慢走，ok；优化二分确定替换位置；
官方另一种表达-动态规划差不多：dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]；


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> res;
        res.push_back(nums[0]);
        int max=1;
        for(int i=1;i<n;i++){
            int j=seek(res,nums[i]); //比数组小 替换； 都没有就放后面
            //cout<<res.size()<<j<<endl;
            if(j==res.size()){
                res.push_back(nums[i]);
                max=max>res.size()? max:res.size();
            } 
            else res[j]=nums[i];
        }
        return max;
    }
    int seek(vector<int> res,int val){  //返回比数组小  2 5-》 2 3
        int n=res.size();
        for(int i=0;i<n;i++){
            if(val<=res[i]){ //可能重复， 2 2 so=
                val=i;
                return val; //递增的，就是第一个比它小的 2 3 7 -》 2 3 5
            }    
        }
        return n;
    }
};

/*
标签居然是二分，和动态规划
我思路：维持一个数组，后续替换到最靠近的位置,错误 存在重复，2 2 （判定条件）

动态规划差不多：dp[i]=max(dp[j])+1,其中0≤j<i且nums[j]<nums[i]

二分+贪心：我思路，在数组里找i-i+1之间，替换i+1，但是查找i--当前j之间用二分优化
*/
