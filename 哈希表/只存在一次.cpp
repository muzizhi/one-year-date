//136、只有一次的数字：整数数组，一个只出现一次，其余两次。要求：线性时间、不使用额外空间，输出一次的元素。
//思路：定义哈希表，对于每个值，hash存储出现几次。然后输出只有一次的。hash存储ok，查找只有一次的有报错。
//更简单的思路：异或：相同为0，不同为1. 异或同一个数两次还是原数。所以设定a，异或整个数列。最后的a值就是那个值。


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash; //左边存 数，hash 对应存次数
        int res;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.count(nums[i])) //hash查找的应该是左边，不是存储的
            {
                hash[nums[i]]=2;
            }
            else
                hash[nums[i]]=1;
        }
        for(int i=0;i<nums.size();i++) //遍历hash表，找 存1的
        {
            //if(hash.count(nums[i])==1) //报错，count找到就输出1
            if(hash[nums[i]]==1)
            {
                res=nums[i];
                break;
            }
        }
        return res; 
    }
};

/*或者利用异或的思路：空间复杂度o（1），上面的复杂度o（n）
int singleNumber(vector<int>& nums) {
       int len = nums.size();
        int result=0;
       for(int i=0;i<len;i++){
           result ^=nums[i];
       } 
        return result;
 }

*/
