//真实恶心，想了好久，调通好久，并且while/if/for之间漏条件各种，也弄了很久
//思路：排序+双指针法。第一个i遍历0-n-2，第二个从i+1，第三个从最右。如果2+3》-1，3左移；反之2右移。注意重复的掠过
// 双指针法+排序
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sum;
        vector<int> tmp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n-2;i++)  //只剩三个数 i、l、r
        {
            //while(nums[i]==nums[i+1])   错误，用while i+，没法直接到for i+
           // if(nums[i]==nums[i+1]) 错误，i=0，第一个跨过去了
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
           // int l=0;   错误，前面的情况已经顺序考察过不可能了，重复操作
            int l=i+1;
            int r=n-1;
            while(l<r){   //错误，否则只有一个输入，每个i
            if(nums[l]+nums[r]==-nums[i])
            {
                //tmp={nums[i],nums[l],nums[r]}; 可以不用clear
                tmp.push_back(nums[i]);
                tmp.push_back(nums[l]);
                tmp.push_back(nums[r]);
                sum.push_back(tmp);
                tmp.clear();
                while(l<r&&nums[l]==nums[l+1]) //可能-1 -1 1 2 2 这样l<r 没有  报错
                    l=l+1;
                while(l<r&&nums[r]==nums[r-1])
                    r=r-1;
                r--;
                l++;
            }
            else if(l<r&&nums[l]+nums[r]>-nums[i])
                r--;
            else 
                l++;
            }
        }
        return sum;
    }
};
