//169、多数元素：给定一个数组，总有多数元素「>1/2」，输出该元素
//思路：存储每一个数，记录次数。哈希表可以存储，过半输出；
//还有一个思路：排序，之后在n/2处的值 一定是多数元素&&还有一个叫摩尔投票法amazing

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++)
        {
            if(hash.count(nums[i]))
            {
                hash[nums[i]]=hash[nums[i]]+1;
            }
            else 
            hash[nums[i]]=1;
            if(hash[nums[i]]>n/2)
            return nums[i];
            cout<<nums[i]<<hash[nums[i]]<<endl;
        }
        return 0; //must push back something
    }
};

/* 过了，但是效率很低
方法一、如果所有数字被单调递增或者单调递减的顺序排了序，那么众数的下标为⌊n/2⌋。 
方法二、如果我们把众数记为+1，把其他数记为−1 ，将它们全部加起来，显然和大于 0 ，从结果本身我们可以看出众数比其他数多。Boyer-Moore 投票算法。  所以为0就把前面的都抛弃，只看后面的。挨个选
java
class Solution {
    public int majorityElement(int[] nums) {
        // Arrays.sort(nums);
        // return nums[nums.length/2];

        int countFlag=0;
        int result = 0;
        for(int i=0;i<nums.length;i++)
        {
            //初次默认第一个。后续每次判断当countFlag为0，意味着之前元素抵消完成。
            if(countFlag==0){
               //赋值新元素作为即将可能要返回的值
                result=nums[i];
            }
            // 即将可能返回的值给当前比，相等+1，不相等-1，累计为0重新赋值新坐标元素。
            countFlag+=(result==nums[i])?1:-1;
        }
        return result;
    }
}

*/
