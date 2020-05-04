//567、字符串的排列：给s1和s2，判断s2是否包含s1的排列
//思路：即使有了全排列也很麻烦，换方式。S1为哈希表次数，每个s2是否in表，改为-1；每个i验证连续是否n个满足。反复报错修改最终超时。。
//官方思路：双指针中比较难的是滑动窗口；用框架写

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;// need =s1, window in s2
        for(char c: s1) need[c]++; //look 初始化为0?
        
        int l=0,r=0;
        int valid=0; //又几个完全频率一样的字符
        while(r<s2.size()){
            char c=s2[r]; // c 是将移入窗口的字符
            r++;
            //进行窗口内数据的一系列更新
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){ //频率一样
                    valid++;
                }
            }
            while(r-l>=s1.size()){  // 判断左侧窗口是否要收缩
                if(valid==need.size()){
                        cout<<s1.size()<<r<<l; //左闭右合，r-l 可以正好为size 10  10  0
                        return true;
                    }
                char d=s2[l];
                l++;
                if(need.count(d)){
                    if(window[d]==need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
             
        }
        return false;
    }
};

// 判断 s 中是否存在 t 的排列




/*
思路：s1 in hash，s2 判定在i在里面的，连续改为1；  然后到没有为止看一下满足不
错误"adc"   "dcda" s2后续可能是成功，但是第一个不符合  加入for尝试,可，
又错了s1多个a存在，所以hash表达不能都0, 修改hash为出现次数， 尝试 70超时
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> hash;
        for(int i=0;i<s1.size();i++){
            //hash[s1[i]]=0; 存在多个时候错误
            if(hash.count(s1[i])&&hash[s1[i]]>=1){
                hash[s1[i]]+=1;
            }
            else hash[s1[i]]=1;
        }
        //s2 判定  i要保证连续
        //错误，s2后续可能是成功，但是第一个不符合,多次循环
        int i=0;
        for(i=0;i<s2.size();i++){
            if(hash.count(s2[i])&&hash[s2[i]]!=0){
                bool t=charinhash(hash,i,s2,s1);
                if(t==true) return true;
            }
        }
        return false;
    }
    bool charinhash(map<char,int> hash,int i,string s2,string s1){
        int c=0;
        while(i<s2.size()){
            if(hash.count(s2[i])&&hash[s2[i]]>0){
                hash[s2[i]]-=1;// visited
                c++;
                i++;
            }
            else break;
        }
        if(c==s1.size()) return true;
        else return false;
    }
};
emmm官方思路了解，看了半天学了一个滑动窗口框架，很不错
https://leetcode-cn.com/problems/permutation-in-string/solution/wo-xie-liao-yi-shou-shi-ba-suo-you-hua-dong-chuang/
*/
