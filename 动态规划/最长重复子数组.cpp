718、最长重复子数组：a和b中公共的最长子数组，返回长度，ab有重复元素
思路：用hash存b，不对b可以重复；动态规划设定dp[i][j]代表以A[i]与B[j]结尾的公共字串的长度,dp[i][j]={dp[i-1][j-1]+1,ifa[i]=b[j]} 
但是不好表示i/j  ，so a[i-1]=b[j-1] 含义替换

/*class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
//*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int m=B.size();
        int res=0;
        if(n==0||m==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1)); //长度有问题，差点错
        //if(A[0]==B[0]) dp[0][0]=1;
       // else dp[0][0]=0;  i和j不好动
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){    //干脆视作dp[i][j]代表以A[i-1]与B[j-1]结尾
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=0;
                res=max(res,dp[i][j]);                
            }
        }
        return res;
    }
};



/*
正常思路，a挨个找，对应b。 那么b要hash，并且顺序连接（hash里面存 索引，然后检查是不是+1）
不对，b中可能有重复，不能用hash， 用动态规划dp[i][j]代表以A[i]与B[j]结尾的公共字串的长度,，
dp[i][j]={dp[i-1][j-1]+1,ifa[i]=b[j]}

*/
