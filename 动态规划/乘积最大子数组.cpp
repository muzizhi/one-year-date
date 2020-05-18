152、乘积最大子数组：数组中乘积最大的连续子数组，至少一个，返回乘积（ps -1*-2=2）
思路：连续滑窗？但是长度不定；那就是动规，不懂区分负数。如果-多个奇数，每个负数前后都保存？只需要从左向右//从右向左 到边-各一个max。没有考虑0的情况，如果有0，按照0分段求积，比较；
知识点：【2020.5.18】
（1）动态规划真的可以，好厉害，同时维护一个fmin保留最小的，最后要fmax（n）
maxF[i] = max(maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i])
minF[i] = min(minF[i - 1] * nums[i], nums[i], maxF[i - 1] * nums[i])



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max=nums[0];
        int mul=1,count=0;
        for(int i=0;i<n;i++){ //如果有0，按照0分段求积
            if(nums[i]!=0){
                mul=mul*nums[i];
                max=max>mul?max:mul;
            }
            else{
                max=max>0?max:0;
                mul=1;
            } 
            if(nums[i]<0)
                count++;  
        }
        //没有0，按照负数求积,如果奇数个 ,从左到右，其实求过了
        mul=1;
        //if(count%2==1){ [-1,0,-2,2]  单个元素
            for(int i=n-1;i>=0;i--){
                //mul=mul*nums[i]; //这里面，不判定0，可以不可以,[-1,-2,-3,0] 不可以，分段可能3个
                //max=max>mul?max:mul;
                if(nums[i]!=0){
                    mul=mul*nums[i];
                    max=max>mul?max:mul;
                }
                else{
                    mul=1;
                } 
            }
        //}
        return max;
    }
};


/*
动态规划，跟和不一样，乘积负数可能也有用
dp[i]=max(dp[i-1]*n[i],1); 要*上， 不要现在就是1 // 不对不能直接max，负数区分
如果-多个奇数， 每个负数前后都保存，不需要只需要从左向右//从右向左 各一个max

错误，没有考虑0的情况，如果有0，按照0分段求积，比较；
错误2，0分段求积，可能每一段《0，所以也要max与0相比
错误：[-1,-2,-3,0]  反向判定0
[-1,0,-2,2]  单个元素


动态规划真的可以，好厉害，同时维护一个fmin保留最小的，maybe负数，最后要fmax（n）
maxF[i] = max(maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i])
minF[i] = min(minF[i - 1] * nums[i], nums[i], maxF[i - 1] * nums[i])


*/
