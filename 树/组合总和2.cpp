//40、组合总和2:给出target和数组，每个只能用一次，但是有多个x，同样输出组合。
//思路：还是回溯，但是注意去重，首先要排序，然后只要从i+1开始的。尝试不行，比如111，可能11x，1xx，其中1xx后续重复。If(not begin，i=i-1）跳过i。

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> res;
         vector<int> temp;
         sort(candidates.begin(),candidates.end());
         combination(res,temp,candidates,target,0,0);
         return res;
    }
    void combination(vector<vector<int>> &res,vector<int> temp,vector<int>& candidates,int target,int sum,int begin)
    {
        if(sum==target)
        res.push_back(temp);
        else{
            for(int i=begin;i<candidates.size();i++)
            {
                //if(i>0&& candidates[i]==candidates[i-1]) continue;
                if(sum+candidates[i]<=target)
                {
                    //if(i>0&& candidates[i]==candidates[i-1]) //需要留第一个，删除后面的
                    if(i>begin && candidates[i]==candidates[i-1])
                    continue;
                    temp.push_back(candidates[i]);
                    sum+=candidates[i];
                    combination(res,temp,candidates,target,sum,i+1);
                    temp.pop_back();
                    sum=sum-candidates[i];
                }
                else
                break;// 剪枝
            }
        }
    }
};
