//17、电话号码的字母组合：对应九宫格，输入2-9的字符，输出所有可能的字符组合。
//思路：对于每个数字，先代换到字符。替换我用switch，还有哈希表的，字符串等。For for for暴力输出？输出可以用回溯法，abc--abe，cur到abc长度输入。
//注意只有1个/0个。

class Solution {
public:
    vector<string> res;
    string cur;
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> s(n);
        if(n==0) return res;
        for(int i=0;i<n;i++)  //替换digits--s
        {
            switch(digits[i])
            {
                case '2': s[i]="abc";break;
                case '3':s[i]="def";break;
                case '4':s[i]="ghi";break;
                case '5':s[i]="jkl";break;
                case '6':s[i]="mno";break;
                case '7':s[i]="pqrs";break;
                case '8':s[i]="tuv";break;
                case '9':s[i]="wxyz";break;
            }
        }
        dfs(s,0);
        return res;
    }
    void dfs(vector<string> s,int k) //回溯法，ad ae
    {
        if(cur.size()==s.size())
        {
            res.push_back(cur);
        }
        else
        {
            string temp=s[k]; //s用完一个abc 拿走一个
            for(int i=0;i<temp.size();i++)
            {
                cur.push_back(temp[i]);
                dfs(s,k+1); //放置后续的
                cur.pop_back();
            }
        }

    }

};
