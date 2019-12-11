//33、搜索旋转排序数组：不重复，但是升序数组分成了两部分。logn范围
//思路：直接找一下数组从那里断开了，但是时间不行。那就一边二分一边找。向左还是向右判定一万个问题
//向左只有三种情况， 前半部分没有旋转，l<= x<m;前半部分旋转了，x《m || x》l，如8 9 0 1。「注意=，and两边都要限定」


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1&&nums[0]==target) //只有一个值时候情况判定
            return 0;
        if(n==0||n==1&&nums[0]!=target)
            return -1;
        int res=search(nums,0,n-1,target);
        return res;
    }
    int search(vector<int> nums,int left,int right,int target) //旋转数组二分查找
    {
        int medium=(left+right)/2;
        cout<<nums[medium]<<endl;
        if(nums[medium]==target)
            return medium;
        if(right-left==1)  //细分类，只有两个值时候 判定。
        {
            if(nums[right]==target)
                return right;
            else
                return -1;
        }
        //按照旋转不旋转分，别盯着大小乱七八糟。
        //第一种情况，45678123 7到8  ，第二种 8123 1到8 ,第三种 513 找3，135 找5,351 找3
        if(nums[medium]<nums[right] && nums[right]>=target&&nums[medium]<target||nums[medium]>nums[right]&&nums[right]>=target ||nums[medium]>nums[right] && nums[medium]<=target) 
            return search(nums,medium,right,target);
        //正常和  m=0,seek 6
        //if(nums[medium]>target && nums[left]<target||nums[medium]<target&&nums[right]<target)
        else
            return search(nums,left,medium,target);
    }
};

/*
很难[4,5,6,7,8,1,2,3] 8  >= >搞了好久 1 3 5 //1 5，还很乱
简要来说：
向左只有三种情况， 前半部分没有旋转，l<= x<m;(左和右都要限定)
前半部分旋转了 ， 89 01   x《m || x》l

其他情况向后规约
也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid] 三项均为真或者只有一项为真时向后规约。



另一个人的思路：
将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
*/
