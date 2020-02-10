//39、组合总和：给出target和数组，数组可重复用，输出所有和为t的组合。
//思路：挺麻烦的，先一个个统计超过退出；再两个遍历？哦乎我傻了，明显又是回溯法思路。回溯树每个都能选，超过退出剪枝，和为t输出一列。
//注意前面试过不可行，从i开始。

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         
         combination(candidates,target,0,0);
         return res;
    }
    void combination(vector<int>& candidates,int target,int sum,int begin)
    {
        if(sum==target)
        res.push_back(temp);
        else{
            for(int i=begin;i<candidates.size();i++)
            {
                if(sum+candidates[i]<=target)
                {
                    temp.push_back(candidates[i]);
                    sum+=candidates[i];
                    combination(candidates,target,sum,i);//不需要重复
                    temp.pop_back();
                    sum=sum-candidates[i];
                }
            }
        }
    }
};
