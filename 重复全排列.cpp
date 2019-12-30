//47、全排列2:给定一个可包含重复数字的序列，返回所有不重复的全排列。如 112 121 211
//思路：还是上面回溯，在排列的时候多加一个判断，如果选择列表一样了，continue。
//但是有点不明白，那个swap不二次用，因为nums不是引用，是复制。所以还是推荐用，数组是否以及搜索flag=true，不用swap，便于理解

class Solution {
public:
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        vector<int> res;
        return permutation(nums,0,res,results);
    }
    vector<vector<int>> permutation(vector<int> nums,int l,vector<int> &res,vector<vector<int>> &results) {
        if(l==nums.size())
        results.push_back(res);  //多加了一次最后，叶子结点 过来
        for(int i=l;i<nums.size();i++)
        {
            if(nums[i]==nums[l]&&l!=i)  //除了首元素，去掉跟首位 重复的元素  ，难以理解后面的咋处理了
            continue;
            res.push_back(nums[i]);
            for(int j=0;j<res.size();j++)
            {
                cout<<res[j];
            }
            cout<<endl;
            swap(nums[i],nums[l]);  //加入swap是能够分类 已处理元素，但是输出顺序不一样eg 321 312
            permutation(nums,l+1,res,results);
            res.pop_back(); // 回溯中的撤销操作   pop-back 是吐出来吗
          //  swap(nums[i],nums[l]);  
          // 不用两次交换，两次交换会导致去重失效。数组部分没有用到引用。每次都是又复制了一个vector传进去，这是大部分人看不懂为什么没有第二个swap也会通过的原因
          
        }
        return results;
    }
};

/*
更好理解
vector<int> temp;vector<vector<int>> res;
    void dfs(vector<int>& nums,int n,vector<int>& vis)
    {
        if(n==nums.size()) {res.push_back(temp);return;}
        
        for(int i=0;i<nums.size();i++)
            if(vis[i]==0)
            {
                if(i>0 && nums[i]==nums[i-1] && vis[i-1]!=0) continue;
                temp.push_back(nums[i]);
                vis[i]=1;
                dfs(nums,n+1,vis);
                vis[i]=0;
                temp.pop_back();
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> vis(nums.size());
        dfs(nums,0,vis);
        return res;
    }

*/
