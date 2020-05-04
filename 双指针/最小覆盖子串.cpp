//76、最小覆盖子串：给一个s，一个t，s中包含t的最小子串。
//思路：子串，滑动窗口，加r找可行解；减l优化，迭代选择，尝试；注意：t中字母个数也要考虑。结束是在while（valid==need。size）

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(char c : t){
            need[c]++;
        }
        int l=0,r=0;
        int valid=0;
        int len=INT_MAX,start=0; //must be large,wrong 可能有无用字符

        while(r<s.size()){
            char c=s[r];
            r++;
            // 处理->
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }
            //收敛条件--终止判定有问题，debanc  abc 可能滑窗口多了
            //while(r-l>=t.size()){
            while(valid==need.size()){
                //cout<<l<<r<<endl;
                if(r-l<=len){ //长度缩小了
                    start=l;
                    len=r-l;
                }
                char d=s[l];
                l++;
                if(need.count(d)){
                    if(window[d]==need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        cout<<start<<len;
        return len==INT_MAX? "":s.substr(start,len);
        //return len == INT_MAX ? "" : s.substr(start, len);
    }
};

/*
学完滑动窗口框架，过来练手。
对于复杂子串的判定，多可以利用滑动窗口解决
substr （start，len） 假设0，4  就是 abcd
INT_MAX  表示无穷大
*/
