//303、区域和检索-数组不变性：给一个数组，给出i-j之间的区间和（含ij）多次调用
//思路：多次调用，所以存前缀和，2-5就是0～5-0～1；

class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int sum=0;
        if(nums.size()==0)
        return;
         //注意新用法，设置未知数组长度
        sums.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            sums[i]=sum;
           // sums.push_back(sum);  也可以
        }
    }
    
    int sumRange(int i, int j) {
        if (i==0) return sums[j];
        else
        return sums[j]-sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 多次调用，前缀和啊，2-5 = 0～5 - 0～1；
 */
