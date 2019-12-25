//11、盛最多水的容器：给定数组作为y轴，i-x轴，min(ai,aj)*(j-i)即面积最大，输出面积
//思路：最简单暴力法双循环，不行。那就双指针，i头j尾，谁高小谁里移，宽变小了，只能高变大点，探究可行性。


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=0;
        int i=0,j=n-1;
        while(i!=j)  //双指针法走起
        {
            int temp=min(height[j],height[i])*(j-i);
            if(res<=temp)
                res=temp;
            if(height[i]<=height[j]) //谁小谁移动，=随意
                i++;
            else j--;
        } 
        return res;
    }
};
