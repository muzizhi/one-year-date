84、柱状图中最大的矩形：给一个序列，画柱状图，组成的矩形最大是多少
思路：寻找每个h，可以组成的区域。问题是左右边界确定-2个栈。找比h低的索引，递增栈就可以，比栈顶j低下来i 进去，还行朴实。
优化方案：可以一个单调栈，递增，当j出栈i时候就是j的右边界，左边界进栈确定是top。答案微错在<=/no<，但是整体结果对。





class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n),right(n);
        //求解两个单调栈，确定h 小的左右边界
        stack<int> s1;
        for(int i=0;i<n;i++){
            //小的替换出top元素,相等也替换 ，必须要小的
            while(!s1.empty()&& heights[i]<=heights[s1.top()]){
                s1.pop();
            }
            left[i]=(s1.empty()? -1:s1.top());
            s1.push(i);
        }
        stack<int> s2;
        for(int i=n-1;i>=0;i--){
            //左右边界没有，就按照-1，和n进行处理，貌认两边边界为0
            while(!s2.empty()&& heights[i]<=heights[s2.top()]){
                s2.pop();
            }
            right[i]=(s2.empty()? n:s2.top());
            s2.push(i);
        }
        //res
        int res=0;
        for(int i=0;i<n;i++){
            res=max( res, (right[i]-left[i]-1)* heights[i]);
        }
        return res;
    }
};

/*
可以使用一重循环枚举某一根柱子，将其固定为矩形的高度h。随后我们从这跟柱子开始向两侧延伸，直到遇到高度小于 h的柱子，就确定了矩形的左右边界。如果左右边界之间的宽度为 w 那么对应的面积为 w∗h。

利用单调栈可以求接触左右边界，然后 对于每个h 确定了一个不低于h的区域高点 。通过max比较就能得到 o（n）/ o（n）
*/
