面试83、魔术索引：找巨长有序数组第一个值=索引的，返回索引或者-1
思路：直接挨个找费时间，二分mid值if>index，右不可能；if值<index，左不可能。Try
错误，多个相等剪枝有问题（0 -1 0 1 see0）。官方思路：值都减去索引，if就一个直接二分；如果多个策略：先找左，mid=输出，没有再找右，宛如直接
更优思路：可重复/顺序上跳变，值if>i，i=值（之间不相等）；if值<i，i=i+1. 




class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==i) return i;
            if(nums[i]>i) i=nums[i];
            else i++;
        }
        return -1;
        
        /*
        int l=0,r=n-1;
        int res=n;  //同时存多个正确值，要最小的
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==mid){
                res=min(res,mid);
            }
            if(nums[mid]>mid){
                r=mid;
            }
            if(nums[mid]<mid){
                l=mid+1;
            }
            //else
            //    l=mid+1;
            cout<<l<<r;
        }
        if(res==n) return -1;
        else return res;
        */
    }  
};


//直接挨个找费时间，二分mid值if>index，右不可能；if值<index，左不可能。try
//停止条件，要最小的
//cuo  [0,0,2] ,左右条件有问题，可以重复数组，不能直接二分
/*别人的思路
while i < len(nums):
            if i==nums[i]:
                return i
            if i<nums[i]:
                i=nums[i]
            else:
                i+=1
        return -1
*/
