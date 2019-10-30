//一列数据，输出数对应序号，和为target
//思路：用哈希表存储，可以一边存一边判断

class Solution { //哈希表
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();
        vector<int> Sum(2,-1); //2 ge ,zhi -1
        for(int i = 0;i<n;i++)
        {
            if(hash.count(target-nums[i]))
            {
                Sum[0]=hash[target-nums[i]]; 
                //Sum.push_back(i);  here can't push back
                Sum[1]=i;
            }
            hash[nums[i]]=i;
        }
         return Sum;
    }
};

class Solution {  //时间复杂度高o（n^2）
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> Sum;
        int n = nums.size();
        for(int i = 0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    Sum.push_back(i);
                    Sum.push_back(j);           
                }
            }
         return Sum;
    }
};
