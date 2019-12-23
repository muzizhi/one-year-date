//452、用最少的箭射破气球：给每一个气球xs范围，y无所谓。if箭x在气球xs中间，该气球爆。求场上所有气球爆的最少箭。
//思路：每次找射最多个的箭，然后消除气球直到结束；怎么找重复区间最多？排序，挨个统计。那每次都要重新统计，浪费。不好
//官方思路：按结束坐标排序，1气球结束坐标处是否有多个气球，有消减气球数量。下一个

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        //sort(points.begin(),points.end()); //这样可能会有一点点问题，想按照结束坐标排序
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){  //真的好用这个sort写法
            if(a[1]<b[1])  return true;
            if(a[1]==b[1]&&a[0]<b[0])  return true;
            return false;
        }
        );
        for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
        {
            cout<<points[i][j]<<' ';
        }
        int i=0,count=0; 
        while(i<n)
        {
            int j=i+1;
            while(j<n&&points[j][0]<=points[i][1]) //找一下i的结束坐标范围前有几个重合的，注意=
            {
                j++;
            }
            count++;
            i=j;
        }
        return count;
    }

};
