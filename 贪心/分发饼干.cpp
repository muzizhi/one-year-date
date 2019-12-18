//455、发放饼干：孩子胃口gi，饼干大小sj，一人一个，s》g满足，输出最多满足孩子数。如：[1,2,3], [1,1]，输出1，数组分别代表孩子胃口、饼干。
//思路：感觉有点像01背包问题那款。整体就是拿小的饼干喂饱胃口最小的宝宝。双排序，双指针，j是否满足i1，不满足j++；满足同时后移。


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,count=0;  //双指针
        while(i<g.size()&&j<s.size())  //胃口排序，喂饱胃口最小的人
        {
            if(s[j]>=g[i])
            {
                i++;j++;
                count++;
            }
            else
                j++;
        }
        return count;
    }
};
