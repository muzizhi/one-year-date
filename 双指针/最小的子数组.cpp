209、长度最小的子数组：给数组和目标s，返回连续子数组和>=s的长度，无为0
思路：暴力超时，统计前缀和+二分判定长度，优化到o(nlogn)
最优官方：双指针，l和r，r右移到超过s，然后左移l看可以减少吗，右r到end结束。


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int len=n,sum=0;
        //少情况，不满足
        int allsum=0;
        for(int i=0;i<n;i++){
            allsum+=nums[i];
        }
        if(s>allsum) return 0;
        //正常情况
        while(r<n){
            while(r<n && sum<s){
                sum+=nums[r];
                r++;
            }
            //更新len，如果sum》s才行
            if(sum>=s)
                len=min(len,r-l); //4-0=4
            //cout<<l<<r<<len<<endl;
            while(sum>=s){
                sum-=nums[l];
                l++;
            }
            //if(sum>=s)  while一定不满足，但是r-l的上一个肯定满足且最短
                len=min(len,r-l+1); //4-1=3; 但是不满足条件
            //cout<<l<<r<<len<<endl;
        }
        return len;
    }
};

/*
和全部存储，然后寻找 5 6 8 12 15 的差，可以用二分判定更快速？可以

标签居然双指针，~~ 滑动窗口（有点像）尝试
最优官方：双指针，l和r，r右移到超过s，然后左移l看可以减少吗，右r知道end结束。

错误在于：如果不存在，我的l++的len有问题
*/
