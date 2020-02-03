//581、最短无序连续子数组：求最小连续子数组长度，如果该无序有序排列，则整体有序。
//思路：先排序完成，然后对照的求第一个不一样的和最后一个不一样的。注意全有序。
//或者双指针不牺牲空间，2 6 4 8 10 9 15从左到右，挨个求max，发现有i《max，输出max为左；从右向左，求min，有大的，输出min为右。Min-max=长度。


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector same(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            same[i]=nums[i];
        }
        sort(same.begin(),same.end()); //copy nums排序，对照看
        int i=0,j=nums.size()-1;
        while(nums[i]==same[i])
        {
            if(i==nums.size()-1)
            return 0;  //必须加，要不然执行错误
            else 
            i++;
        }
        cout<<i;
        while(nums[j]==same[j]&&j>=0)
        {
            j--;
        }

        if(j>i) return j-i+1; //1 2 3 4
        else return 0;
    }
};
