//78、子集：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//思路：挨个输出单个，2个，3个，n个元素+空集。其中判定n个数输出k个有点麻烦，按照标准的回溯树方法可以实现，over（有点慢就是，因为遍历k还）
//还有思路是：就是每个数都有要或者不要两个选择，直接利用回溯数，不尽兴n选k，遍历k。
//或者：for循环从前向后遍历，for已有的子集，加上新的数构成新的子集加进去

class Solution {
public: 
    vector<vector<int>> results;
    vector<int> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<bool> flag(n,0);
        
        results.push_back({}); //空集咋push-back
        for(int i=1;i<=n;i++)
        {
            subset(nums,0,i,flag);
        }
        return results;
        
        
        //return subset(nums,0,2,flag);;
    }
    vector<vector<int>> subset(vector<int> nums,int l,int k,vector<bool> &flag) { //给出n个数的 只含k个数的数组
        if(k==0)
        results.push_back(res);
        else{
        int temp=nums.size()-k;
        for(int i=l;i<=temp;i++)  //防止重复，1234 找3个元素的 搜到2停止
        {
            if(flag[i]==0)  //固定框架，对于选择列表，进行   选择，更新列表，撤销操作
            {
                res.push_back(nums[i]);
                flag[i]=1;
               // subset(nums,l+1,k-1,flag);
                l=i; //下一次的搜索 从nums【i】后面开始,只搜索后面的元素
                subset(nums,l,k-1,flag);
                res.pop_back();
                flag[i]=0;
            }
        }
        }
        return results;
    }
};

/*
递归回溯法，关键思路：每个数字都有取与不去两种选择 直接利用递归调用，会快一点
public: 
    vector<vector<int>> results;
    vector<int> res;
    vector<vector<int>> subsets(vector<int>& nums) {  
        subset(nums,0);
        return results;
    }
    vector<vector<int>> subset(vector<int> nums,int l) { //给出n个数的 只含k个数的数组
        results.push_back(res);
        for(int i=l;i<nums.size();i++)  //防止重复，1234 找3个元素的 搜到2停止
        {
                res.push_back(nums[i]);
                subset(nums,i+1);//下一次的搜索 从nums【i】后面开始,只搜索后面的元素
                res.pop_back();
        }
        return results;
    }

大神新思路：这个题蛮有意思的，可以直接从前往后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
public static List<List<Integer>> enumerate(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res.add(new ArrayList<Integer>());
        for (Integer n : nums) {
            int size = res.size();
            for (int i = 0; i < size; i++) {
                List<Integer> newSub = new ArrayList<Integer>(res.get(i));
                newSub.add(n);
                res.add(newSub);
            }
        }
        return res;
    }

*/
