394、字符串解码：数字表示重复次数[string],eg：3[a2[c]] =accaccacc。
思路：数字for，if string添加，if num循环，wrong需要括号匹配，迭代试了1hwrong，不懂。
后来采用栈结构表示，存储数字和string，然后string顶上时刻更新着cur+n*cur。

class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        int num=0;
        string res="";
        string cur="";
        stack<string> strstack;
        stack<int> numstack;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num = 10*num + s[i] - '0';
            }
            else if(s[i]=='['){
                strstack.push(cur);
                numstack.push(num);
                cur.clear(); num=0;
            }
            else if(isalpha(s[i])){
                cur+=s[i];
            }
            else{ //]应该出栈了
                int c=numstack.top();
                numstack.pop();
                for(int j=c;j>0;j--){
                    //res+=cur; //wrong 直接+只能保存一个，cur清空了   "3[a2[c]]"=acc
                    strstack.top()+=cur; //two cc
                }
                //cout<<cur;
                cur=strstack.top();//  cur=2[c] =cc,可以下一层
                strstack.pop();
                //cout<<cur<<endl;
            }
        }
        return res+cur;
    }
};

/* 数字就循环，非数字直接+string。 不对，有【】括号匹配限制
要不然就是迭代：折腾1h报错 
我是for (i; s[i] != ']' && i < s.size(); ++i)  ；然后就会只能到第一个右括号前面的出来

要不然用栈结构匹配：凡是遇到左括号就进行压栈处理，遇到右括号就弹出栈，栈中记录的元素很重要。


正确的，不知道为啥：public:
    int i = 0; //why 放前面可以，放for里面不行，不懂
    string decodeString(string s) {
        string res = "", temp = "";
        for (; s[i] != ']' && i < s.size(); ++i) {
            if (isalpha(s[i]))
                res += s[i];
            else {
                int t = 0;
                while (isdigit(s[i]))
                    t = t * 10 + (s[i++] - '0');
                ++i;
                temp = decodeString(s);
                while (t--)
                    res += temp;
            }
        }
        return res;
    }

*/
