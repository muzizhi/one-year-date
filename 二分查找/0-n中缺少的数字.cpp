剑指53、0-n中缺失的数：就递增数组长度n，每个数唯一且为[0，n]，缺少哪个数？
思路：这直接vector存完，然后次数++，输出0值的索引，空间太大了。
优化：二分。排序，so如果mid=mid l=mid+1，or前面；wrong/if缺的是n，我只能默认到n-1。加入制约。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==mid){
                l=mid+1;
            }
            else
                r=mid;
        }
        //return l;//wrong
        if(l==n-1 &&nums[l]==l) l=n;
        return l;
    }
};


//优化：二分。排序，so如果mid=mid 后面有问题，or前面
// wrong in [0,1,2,3,4,5,6,7,8]，应该是9的，还是8. 就是如果缺的是n，搞不定我只能默认到n-1.
//制约，如果l=n-1，l不对，那就是l；l对那说明是n。
