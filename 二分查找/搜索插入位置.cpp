//35、搜索插入位置：给定一个排序数组和整数，返回目标值索引（012）或应插入位置
//思路：为了简化搜索次数，利用二分查找。注意判定比整个数组大或者小（r-l=1细分）

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0||n==1&&nums[0]>target) //只有一个值时候情况判定
            return 0;
        if(n==1&&nums[0]<target)
            return 1;
        int res=search(nums,0,n-1,target);
        return res;
    }
    int search(vector<int> nums,int left,int right,int target) //二分查找
    {
        int medium=(left+right)/2;
        if(nums[medium]==target)
            return medium;
        if(right-left==1)  //细分类，只有两个值时候对于插入判定。
        {
            if(nums[left]<target&&target<nums[right])
                return left+1;
            if(nums[right]<target)
                return right+1;
            if(nums[right]==target)
                return right;
            //if(nums[left]>target)
            else
                return left;
        }
        if(nums[medium]<target)
            return search(nums,medium,right,target);
        //if(nums[medium]>target)
        else
            return search(nums,left,medium,target);
    }
};
