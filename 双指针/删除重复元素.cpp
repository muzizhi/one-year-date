//26、删除数组中的重复元素：数组重复排序，将原数组改为前x个不重复，返回长度x；
//思路：排序后，对比有无重复，不一致的数据，挨个移到前面。输出count和数组
//官方：一样的思路，居然叫做快慢双指针。j全局for，当 nums[j] ！=nums[i] 时，跳过重复项的运行已经结束，因此我们必须把它（nums[j]）的值复制到 nums[i+1]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums[count]) // nums[count] 挨个存储新值
            {
                count++;
                nums[count]=nums[i];// 存储一波不一样的 新值
            }
        }
        cout<<count;
        return count+1;
    }
};
