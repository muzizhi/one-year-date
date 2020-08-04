1223、掷骰子模拟：每次出1-6间数，n骰子要求数组，i不能连续超过x个
思路：不是很好想，dp[n][2][count]=+dp[n-1][2][count-1] || +dp[n-1][k][c] 代表骰子/点数/连续个数，
然后最后求解dp[n][++][++];开始值应该是dp[1][x][1]=1;注意roll【i-1】0开始


class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        cout<<rollMax[1];// 123456 cout=2!!
        //int dp[n+1][7][16];
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(16, 0)));
        int mod=1e9+7;
        for(int i=1;i<=6;i++){
            dp[1][i][1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=6;j++){ //固定求dp【i】【2】
                for(int k=1;k<=6;k++) {  //分开加里面要 dp【i-1】【k】
                    if(k==j){
                        for(int c=1;c<rollMax[k-1];c++){ //<c ，wrong k-1对应关系
                            dp[i][j][c+1]+=dp[i-1][j][c];
                            dp[i][j][c+1] %= mod;
                        }
                    }
                    else{
                        for(int c=1;c<=rollMax[k-1];c++){
                            dp[i][j][1]+=dp[i-1][k][c];  //dp[1]
                            dp[i][j][1] %= mod;
                        }
                    }
                } 
            } 
        }
        int res=0;
        for(int j=1;j<=6;j++){
            for(int c=1;c<=rollMax[j-1];c++){  //roll从1开始，但是对应roll【0】wrong
                res+=dp[n][j][c];
                res%=mod; //每步mod，防止超过int
            }
        }
        return res;
    }
};


//dp[n][2][count]=+dp[n-1][2][count-1] || +dp[n-1][k][c] 骰子/点数/连续个数
//最后求解dp[n][++][++];
