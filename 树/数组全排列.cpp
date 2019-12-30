//46、数组全排列：给定一个没有重复数字的序列，返回其所有可能的全排列
//思路：固定一个，其余全排；递归输出，结果只有两个可以给出排序。但是递归很难最后输出多个序列；
//考虑回溯（就是穷举遍历），找到一个后再回去找下一个。固定结构回溯法。构造回溯树🌲
//另外还有一个思想，也很巧妙，好理解。按顺序去掉一个，然后挨个插入0-n-1的间歇。


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> res;
        return permutation(nums,0,res,results);
    }
    vector<vector<int>> permutation(vector<int> nums,int l,vector<int> &res,vector<vector<int>> &results) {
        if(l==nums.size())
        results.push_back(res);  //多加了一次最后，叶子结点 过来
        for(int i=l;i<nums.size();i++)
        {
            res.push_back(nums[i]);
            swap(nums[i],nums[l]);  //加入swap是能够分类 已处理元素，但是输出顺序不一样eg 321 312
            permutation(nums,l+1,res,results);
            res.pop_back(); // 回溯中的撤销操作   pop-back 是吐出来吗
            swap(nums[i],nums[l]);
        }
        return results;
    }
};

/*
//还有很多人利用了回溯
vector<vector<int>> ans;
    void permutation(vector<int> nums,int s,int e)
    {
        if(s==e) 
        {
            ans.push_back(nums);  //到树的底端，直接把 现在的nums 输出
            return;
        }
        for(int i=s;i<=e;i++)
        {
            swap(nums[i],nums[s]);
            permutation(nums,s+1,e);
            swap(nums[i],nums[s]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0,nums.size()-1);
        return ans;
    }
或者
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> res;
        vector<bool> flag(nums.size(),false);//标记元素是否被访问过
        return HDFS(results,res,flag,nums,0);
    }
    vector<vector<int>> HDFS(vector<vector<int>> &results,vector<int> &res,vector<bool> &flag,vector<int> nums,int dep){
        if(dep==nums.size()){//达到树叶
            results.push_back(res);
        }
        for(int i=0;i<nums.size();i++){//每层都对每个节点进行检测
            if(!flag[i]){
                flag[i]=true;//访问节点
                res.push_back(nums[i]);
                HDFS(results,res,flag,nums,dep+1);  //进入下一层
                res.pop_back();//往上一层回退
                flag[i]=false;
            }
        }
        return results;
    }
};

*/
