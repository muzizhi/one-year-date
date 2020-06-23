131、分割回文串：s字符串，把s分割为若干回文子串，输出所以可能
思路：回溯树中添加一个回文判定分函数。难点：这次的回溯，depth不固定，设为l，r。& 回溯for里面，也是l开始，每次截取i个，一直走到r。


class Solution {
public:
    vector<vector<string>> res; 
    vector<string> temp;  
    vector<vector<string>> partition(string s) {
        int n=s.size();
        if(n==0) return res;
        dfs(s,0,n-1);
        return res;
    }
    void dfs(string s,int l,int r){          
        //if(depth==)//几个depth不固定
        if(l>r){  //why l>=r 不全，l>r 不显示  ---no return
            res.push_back(temp);
            return;
        } 
        for(int i=1;i<=r-l+1;i++){// 每次截取几个， 123 最长截取长度3= 3-1+1
            if(iscircle(s.substr(l,i))){
                temp.push_back(s.substr(l,i));
                dfs(s,l+i,r);//最后一个还有 1个，l=r; so if end is l>r
                temp.pop_back();
            }
        }
    }

    bool iscircle(string s){
        int j=s.size()-1;
        int i=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
};

/*
比普通的回溯还加了判定-回文数
回溯树中 添加一个回文判定分函数
难点：
（1）这次的回溯，不一定是几个depth不固定，设为l，r
(2)回溯for里面，也是l开始，每次截取i个，一直走到r

为啥报错？ why l>=r 不全，l>r 不显示  ---no return
*/
