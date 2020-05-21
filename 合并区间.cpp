56、合并区间：给区间的集合，合并重叠的区间
思路：先三维数组排序第一个。If 第一个和后一个 a12》a21 那就合并。bug排序之后的可能还需要2次合并，
eg19 23 45直接if 换成while，确定l 和r，统一push—back。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return {};
        sort(intervals.begin(),intervals.end()); //需要分开吗，不用 amazing
        vector<vector<int> > merged; //2维数组
        int i=0;
        while(i<n){ 
            int l=intervals[i][0],r=intervals[i][1];
            //while(i<n-1&& intervals[i][1]>=intervals[i+1][0]){ //wrong, 19 23 45-19
            while(i<n-1&& r>=intervals[i+1][0]){ 
                r=max(intervals[i+1][1],r);
                i++;
            }
            vector<int> temp={l,r};
            merged.push_back(temp);  //一直报错，说没有定义merged
            i++;
        }
        return merged;
    }
};


/* 13  25 =15
如果 第一个和后一个 a12》a21 那就合并。 但是这里按照顺序吗，三维数组咋排序，排序第一个吗，直接能ok

bug，排序之后的可能还需要2次合并，oooo直接if 换成while
原wrong代码：
while(i<n){
            if(i<n-1&& intervals[i][1]>=intervals[i+1][0]){ // 13  25=15
                vector<int> temp={intervals[i][0],max(intervals[i+1][1],intervals[i][1])};
                merge.push_back(temp);
                i+=2;
            }
            else{
                merge.push_back({intervals[i][0],intervals[i][1]});
                i++;
            } 
        }
*/
