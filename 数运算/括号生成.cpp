//22、括号生成：输入数字几对，输出所有可能的括号序列
//思路：有点难啊，全排按说回溯。但是选择列表不好定回溯树。然后有说利用递归，写一个n=2的，n=3的就是（）两队；（一对）一对；（两队）；
//就是left+right=n-1，三层循环。
//官方思路：正常的bfs深度遍历加上条件限制剪枝，这居然算没有回溯思想没有回。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) res.push_back("");
        //if(n==1) res.push_back("()");  去掉就对了，加上就会重复错误
        for(int c=0;c<n;c++)
            for(string left:generateParenthesis(c)) //这个不太会写注意语法
                for(string right:generateParenthesis(n-1-c))
                {
                    res.push_back("("+left+")"+right);
                }
        return res;
    }
};

/*好慢啊运行的，我写的
问题被分为最左侧"("和其对应的")"中间部分和")"右侧部分两个子问题。递归求解子问题即可。
用hash_map记录找到的每个子问题的解，空间换时间。

public:
    vector<string> generateParenthesis(int n) {
        vector<string> results; 
        std::unordered_map<int, vector<string>> subs;
        if(n==0)
            results.push_back("");
        else{
            vector<string> temp1;
            vector<string> temp2;
            for(int i =0;i < n;++i){
                if(subs.find(i)==subs.end()) subs[i] = generateParenthesis(i);
                if(subs.find(n-i-1)==subs.end()) subs[n-i-1] = generateParenthesis(n-i-1);
                temp1 = subs[i];
                temp2 = subs[n-i-1];
                for(auto str1 = temp1.begin();str1<temp1.end();++str1)
                    for(auto str2 = temp2.begin();str2<temp2.end();++str2){
                        
                        results.push_back("("+*str1+")"+*str2);
                    }
            }
        }
        return results;
    }
};

如果我们还剩一个位置，我们可以开始放一个左括号。 如果它不超过左括号的数量，我们可以放一个右括号。
这居然算事回溯法Java 明明是dfs+剪枝
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    public void backtrack(List<String> ans, String cur, int open, int close, int max){
        if (cur.length() == max * 2) {
            ans.add(cur);
            return;
        }

        if (open < max)
            backtrack(ans, cur+"(", open+1, close, max);
        if (close < open)
            backtrack(ans, cur+")", open, close+1, max);
    }
}

*/
