327、区间和的个数：给一个数组，1个算区间，返回区间和在low-high之间的个数。优化
思路：老土方法求前缀和数组，然后挨个区间片段判定时间长；优化方法1:采用的是mulitiset结构，快速获取pre-up< s[j]<pre-low 个数 ;
优化2用归并排序思想，大体是：low< s[i]-s[j] <up统计个数，s差个数的一边排序，一边统计（有序统计更快，设立start/end）


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        multiset<long long> sum;  //数组前缀和
        // multiset<int64_t> S;
        sum.insert(0);  //不加就错，就变成了001 ，现在是113
        long long presum=0;
        int ans=0;
        //统计s【i】，同时确认一下pre-up  -- pre-low之间的个数
        for(int i=0;i<n;i++){
            presum+=nums[i];
            ans+=distance(sum.lower_bound(presum-upper),sum.upper_bound(presum-lower));
            //cout<<ans<<endl;
            sum.insert(presum);
        }
        return ans;
    }
};


/*
区间包括：单独自己，两个。。。。直到n个


改善思路：用一个结构，可以快速获取，  pre-up< s【j]<pre-low 个数 ，结构采用的是mulitiset结构
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n= nums.size();
        int64_t presum = 0;
        multiset<int64_t> S;
        S.insert(0);
        int ret = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            ret += distance(S.lower_bound(presum-upper),S.upper_bound(presum-lower));
            S.insert(presum);
        }
        return ret;
    }        
};
改善思路2:用归并排序思想，看了一个多小时，半知半解。大体意思是：low< s[i]-s[j] <up，我们想统计这样的，如果有序的话，s差的统计可以一边排序，一遍统计（有序统计更快，设立start/end）

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int64_t> S(n+1,0);
        // vector<long long> sum(nums_size+1);  可以用longlong进行设定
        vector<int64_t> assist(n+1,0);
        for(int i=1;i<=n;i++)S[i] = S[i-1] + nums[i-1];
        //sum.at(i+1)=nums.at(i)+sum.at(i);  可以用at表示
        
        return merge(S,assist,0,n,lower,upper);
        
    }
    int merge(vector<int64_t> &S,vector<int64_t> &assist,int L,int R,int low,int up){
        
        if(L >= R) return 0;
    
        int cnt = 0;
        int M = L + (R-L)/2;
        cnt += merge(S,assist,L,M,low,up);
        cnt += merge(S,assist,M+1,R,low,up);
        int Left = L;
        int Upper = M+1,Lower = M+1;
        while(Left <= M){
            while(Lower <= R && S[Lower] - S[Left] < low)Lower++;
            while(Upper <= R && S[Upper] - S[Left] <= up)Upper++;

            cnt += Upper - Lower;
            Left++;
        }
        //以下为归并排序中归并过程
        Left = L;
        int Right = M + 1;
        int pos = L;
        while(Left<= M || Right <= R){
            if(Left > M)assist[pos] = S[Right++];
            if(Right > R && Left <= M)assist[pos] = S[Left++];
            
            if(Left <= M && Right <= R){
                if(S[Left] <= S[Right])assist[pos] = S[Left++];
                else assist[pos] = S[Right++];
            }
            pos++;     
        }
        for(int i=L;i<=R;i++)S[i] = assist[i];
        return cnt;
    }
};

*/
