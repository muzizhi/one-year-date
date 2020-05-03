class Solution {
public:
    vector<string> permutation(string s) {
        //为了去重，需要字符串数组排序
        sort(s.begin(),s.end());
        vector<string> result;
        string res; //每一个字符
        vector<bool> flag(s.size(),false);//标记元素是否被访问过
        huisu(s,result,res,flag,0);
        return result;
    }
    void huisu(string s,vector<string> &result,string res,vector<bool> flag,int dep){
        if(dep==s.size()){
            result.push_back(res);
        }
        for(int i=0;i<s.size();i++){
            if(flag[i]==false){
                if(i>0 && s[i]==s[i-1] && flag[i-1]==true) continue;
                flag[i]=true;
                res=res+s[i];
                huisu(s,result,res,flag,dep+1);
                flag[i]=false; //hui su
                //str = str.substr(0, str.length() - 1);或者可以pop-back
                res.pop_back();
            }
        }
    }
};

/*
回溯算法怎么写，忘了，跟全排列很像
常用：res.pop_back();//往上一层回退
res.push_back() /res.emplace_back() //对应插入
错误，有个问题，没有去掉重复序列
字符串排序：
flag加入判定，if(i>0 && s[i]==s[i-1] && flag[i-1]==true) continue;
*/
