每日练习：硬币：有25、10、5、1分值的硬币，总共n分，几种分法。
思路：有点难哦，5两种；10=10/5+5 2*2-1；25=？找不到明显的推理重复序列难解决。
正确题解：背包问题最好理解，每个硬币要或者不要。dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j]。4中90分=要25/4种75+不要/3种90分。
可以简化用一个数组dp[j]实现。从0一直求解到res(n)，所以会保存中间结果减少重复计算。




class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n+1,0);
        vector<int> coin={25,10,5,1};
        //dp[0]=0;
        dp[0]=1  // 没有硬币凑0分为1种方式
        for(int i=0;i<4;i++){ //很难懂，多练习背包问题
            for(int j=coin[i];j<=n;j++)//小于不可能有值，加速计算
            {
                if(j==coin[i])
                dp[j]=dp[j]+1;
                if(j>coin[i])
                dp[j]=dp[j]+dp[j-coin[i]];
                cout<<j<<" "<<dp[j]<<endl;
            }
            cout<<endl;
        }
        int mod=1000000007;
        return dp[n]%mod;;
    }
};

/*有点难，这个题目
最好理解可以看成一个完全0-1背包问题
每个硬币有两种状态：取或不取
class Solution {                 //一维动态规划
    public int waysToChange(int n) {
        int dp[] = new int[n+1];
        int[] tokens = {1,5,10,25}; 
        int mod = 1000000007;
        for(int i=0;i<4;i++){
            for(int j=1;j<=n;j++){
                if(tokens[i]==j){               //硬币刚好等于当前面额
                    dp[j] = (dp[j] + 1)%mod;
                }else if(tokens[i]<j){         //硬币小于当前面额
                    dp[j] = (dp[j] + dp[j-tokens[i]])%mod;
                }                               //硬币大于当前面额，dp[j] = dp[j]，省略了
            }
        }
        return dp[n];
    }
}

或者说为了避免重复，每次小循环只用一种硬币可以避免重复，因为每次小循环中选用的硬币是固定的，在没有到对应硬币的循环前，表内记录对应的解必然不包含该硬币。
*/
