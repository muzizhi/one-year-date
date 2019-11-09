//5、最长回文子串：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。“babad”，输出: “bab”或者“aba”
//思路：利用已找到的回文数找更大的回文数。x为中心，向两边扩充（只考虑奇数情况)错误
//官方思路：动态规划，d[i,j]=true回文 if si=sj, d[i,j]=d[i+1,j-1];
//so直观的动态规划：长度1和2的自己判定，之后开始填表，1代表奇数//2代表偶数… 时空复杂度：o（n2）
//中心扩展算法：减少空间复杂度到o（1），回文从中心展开，向两边扩充。共有2n-1个中心，分开计算（我的思想）
//如果是偶数，字母数为偶数的回文的中心可以处于两字母之间（例如“abba”）

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int l=0,r=0;
        int len,max=1;//动态规划
        //vector<vector <int>> dp(n,n); 
        vector<vector <int>> dp(n,vector<int>(n)); //定义二维动态数组
        
        for(int i=0;i<n;i++) //对于 长度 1 和 2的先单独赋值
        {
            dp[i][i]=1; // 1 = true
            if(i<n-1 && s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                l=i;
            }
        }
        
        for(int len=3;len<=n;len++) //对 长度3以上的进行赋值， 设立开始点和长度 做双层循环
            for(int i=0;i+len-1<n;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                    if(max<len&&dp[i][j]==1)
                    {
                        max=len;
                        l=i;
                    }
                }
            }
        return s.substr(l,max); //输出从l开始，长度为 max 的子串
    }
};




/*
1、动态规划法 令dp[j][i]从字符串j到i是否为回文串
动态回归方程 dp[j][i]是看j+1和i-1是否为回文串.

dp[i][i]=1; //单个字符是回文串
dp[i][i+1]=1 if s[i]=s[i+1]; //连续两个相同字符是回文串
然后比较长度为3的、4的、列表完成数值
实现代码：C++，T(n) = O(n^2) = S(n)

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        return s.substr(start,max);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
 
C++优化，T(n) = O(n^2)，S(n) = O(n) ，没看懂

class Solution {
public:
    string longestPalindrome(string str) {
        const int n = str.size();
        if(n < 2) return str;
        int s = 0, e = 0;
        int dp[n] = {0, };
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < j; ++i){
                if(!(dp[i] = dp[i + 1] || str[i] != str[j]) && (e - s) <= (j - i)) 
                    s = i, e = j;
            }
        }
        return str.substr(s, e - s + 1);
    }
};

2、中心扩展法--以每个字母为回文中心,考虑回文长度为奇数和偶数的情况.
中心扩展法，从头到尾遍历，寻找最长的回文子串，比较长度，保存start 和 end

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1)
            return s;
        int start(0), end(0);
        int maxLen(0);
        for (int i = 0; i < s.size(); i++){
            int len1 = findSameLength(s, i, i);
            int len2 = findSameLength(s, i, i + 1);
            if (maxLen < max(len1, len2)){
                maxLen = max(len1, len2);
                start = i - (maxLen - 1) / 2; //确实是因为有奇数和 偶数 要注意
                end = i + maxLen / 2; //start 和 end不同要注意
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    int findSameLength(string &s, int left, int right){
        while (left >= 0 && right < s.size() && s.at(left) == s.at(right))
            left--, right++;
        return right - left - 1;
    }
};


3、马拉车算法，时间复杂度提高到线性；
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
*/
