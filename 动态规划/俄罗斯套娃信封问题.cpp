354、俄罗斯套娃信封问题：a的宽和高都比b大，则可以叠放，问叠放信封数目。
思路：先宽排序，然后比较高的大小；问题优化：宽相同，高要降序，这样才能单比高的递增子序列长度。
优化2:关于求解二分+动规。二分可以直接写/利用stl


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        //下面就是对于 h进行 最长递增子序列查找，二分可以更快，从o（n2）-o（nlogn）
        vector<int> dp(envelopes.size(),1);
        int max=0;
        //重点是，找aj《ai 237/5，没有就长度++，有替换后面的
        for(auto&en :envelopes){
            int l=0,h=max;
            while(l<h){
                int mid=l+(h-l)/2;
                //cout<<mid;
                if(dp[mid]<en[1]){
                    l=mid+1;
                }
                else
                    h=mid;
            }
            //最后剩三个，l mid r，结果小的下一个在l.  折腾半天，纠结
            dp[l]=en[1];
            //cout<<dp[l]<<endl;
            if(l==max){
                max+=1;
            }
        }
        return max;
    }
};


/*
先排序要不，好难搞， 然后比较大小；但是 24  26  35这种1相同的怎么比较；
优化思路：
（1）第一个有序，只比较第二个的序列，最长子序列多少就好了
（2）这要求，第二个序列 在1相同的时候，降序排列。防止同等w的组合
（3）可以更优化

class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes_1(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){  //如果前面有一个元素小的话，就是那个地方dp+1 。跟自己1对比
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();  //在里面找比en【1】小一点的元素
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};

*/
