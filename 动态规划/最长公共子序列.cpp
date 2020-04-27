//1143、最长公共子序列：两个字符串，按顺序有叫子序列，可间隔eg abcde 和dce
//思路：思路断，短的第一个没有，第二个可能有，挨个for太长。懵咋dp，dp画表get可以发现右下=max（左，上）+ 如果=为1/如果新地方不等0。方程错误，
还是按转化思路，如果=为1，那就加上之前的dp[i-1][j-1]+1// 如果=0 就取两边目前最大max（左，上）。

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        if(m==0||n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){ //第一行 第一列 只能max继承 单方向
                    if(text1[i]==text2[j]) dp[i][j]=1;
                    else dp[i][j]=0;
                }
                if(i==0&&j!=0){ //第一行 要不然1，要不然 只能max继承 单方向
                    dp[i][j]=dp[i][j-1];
                    if(text1[i]==text2[j]) dp[i][j]=1;
                }
                if(i!=0&&j==0){ //第一列 只能max继承 单方向
                    dp[i][j]=dp[i-1][j];
                    if(text1[i]==text2[j]) dp[i][j]=1;
                }
                if(i>0&&j>0){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                }
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
};

/* 经典的考题
如果dp，一维度的不好说 a是，找a，不是，找c？？莫名其妙
列表，可以发现规律
   a b c d e j/2
d  0 0 0 1 1
c  0 0 1 1 1
e  0 0 1 1 2
i/1
seek 发现 右下=max（左，上）+ 如果=为1/如果新地方不等0

错误例子："bsbininm" "jmjkbkjkv" 1里面2个b，在2里面同时重合了1个b，多算了一次
"lcnqdmvsdopkvqvejijcdyxetuzonuhuzkpelmva"
"bklgfivmpozinybwlovcnafqfybodkhabyrglsnen"

转移方程找错了
这两个字符不是公共的字符，只要考察其两个子问题 max（左，上+0）/是公共 则是 左上+1；

可以优化，1 从1-n+1；1-m+1起 2 二维变1维
*/
