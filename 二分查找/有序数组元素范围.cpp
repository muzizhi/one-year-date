//34、排序数组中位置范围：给定一个排序数组和整数，返回目标值位置范围或【-1，-1】
//思路：要求用二分。整体一样，存在重复数组，那就要medium=target对其左右while判定范围。其余剪枝，只剩两个的时候给出结果判定。


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0||n==1&&nums[0]!=target) //只有一个值时候情况判定
            return {-1,-1};
        if(n==1&&nums[0]==target)
            //return [1,1];  用{}
            return {0,0};
        vector<int> res=search(nums,0,n-1,target);
        return res;
    }
    vector<int> search(vector<int> nums,int left,int right,int target) //二分查找
    {
        int medium=(left+right)/2;
        if(nums[medium]==target) //相等时候的判定
        {
            int a=medium,b=medium;
            while(a>=left&&nums[a]==target)  //a比0小咋办
                a--;
            while(b<=right&&nums[b]==target)  //b比n大咋办
                b++;
            return {a+1,b-1};
        }
        if(right-left==1)  //细分类，只有两个值时候对于插入判定。 =r;!=
        {
            if(nums[right]==target)
                return {right,right};
            if(nums[left]!=target&&target!=nums[right])
                return {-1,-1};
        }
        if(nums[medium]<target)
            return search(nums,medium,right,target);
        //if(nums[medium]>target)
        else
            return search(nums,left,medium,target);
    }
};
