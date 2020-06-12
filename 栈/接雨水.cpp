42、接雨水：给一个序列，画柱状图，能接多少单位面积的雨水
思路：高低高之间接水，单调栈的应用？递减放，i比栈顶j大的pop，到下一个top，记个宽i-j-1；然后高就是比较弱的那一方高度- 被out的前栈顶元素，累计超时？？I++
官方暴力法思路：从左遍历max1对应最高；从右too；然后height累计min（max12）-hi
引申双指针：右高依靠左，跟新max和非最大res+=left_max−height[left]；反之亦然。



class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s; //单调递增；
        int res=0;
        int n=height.size();
        int i=0,kuan=1,gao=0;
        while(i<n){  //栈内放的是索引，好知道宽度
            while(s.size()>=1&& height[i]>height[s.top()]){
                int temp=s.top();
                s.pop();
                if(s.empty()) break;  //倒数第二个pop已经计算了，最后一个直接pop
                kuan=i-s.top()-1;
                gao=min(height[s.top()],height[i])-height[temp];
                res+=kuan*gao;
                //cout<<kuan<<gao<<res<<endl;
                
            }
            s.push(i);
            i++; //wrong,forget so runtime
        }
        return res;
    }
};



/*
高低高之间接水，单调栈的应用？递减放索引，i比栈顶j大的pop，到栈底/》i，记个宽i-j-1；
然后高就是比较弱的那一方高度- 被out的前栈顶元素，可以求出体积。 

超时，why，看下官方, 忘记i++；忘记 if(s.empty()) break;

双指针最高级的 o（n） o（1） 看一眼：
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

*/
