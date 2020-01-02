//90、子集2:数组中可能含有重复元素，要求子集不能重复依旧
//思路：真的很简单，就多一句话。对于非第一个数，后面重复的部分忽略continue，标准的迭代数做法。

class Solution {
public:
    vector<vector<int>> results;
    vector<int> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        subset(nums,0);
        return results;
    }
    vector<vector<int>> subset(vector<int> nums,int l) { //给出n个数的 
        results.push_back(res);
        for(int i=l;i<nums.size();i++)  //防止重复 只搜索后面的
        {
                if(i>l&&nums[i]==nums[i-1]) //把 1 2 2 重复的部分都先只保留一个，不影响
                continue;
                res.push_back(nums[i]);
                subset(nums,i+1);//下一次的搜索 从nums【i】后面开始,只搜索后面的元素
                res.pop_back();
        }
        return results;
    }
};
