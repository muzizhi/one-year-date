151、翻转字符串里的单词：翻转字符串中的每个单词。多余空格只保留1个，前后无空
从"the sky is blue" 到"blue is sky the" 
思路：按照正经操作慢慢搞，就temp保存单词，然后s=“”+temp。思路2: 全部反转一遍，然后再单独翻转单词，去空格。
//我怎么回事，这么简单写了2h，去除空格写了好久

class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return ""; 
        reverse(s.begin(), s.end());
        int i=0;
        while(i<s.size()){
            int left=i;
            while(i<s.size()&&s[i]!=' '){  //容易报错
                i++;
            }
            int right=i;
            if(left!=right){//有一个单词
                reverse(s.begin()+left,s.begin()+right); //翻转必须，左，右都给
            }
            //cout<<s<<endl;
            if(s[i]==' ') i++;
        }
        //去除空格 -折腾了好久好久
        int j=0,a=0; // i 保留正确的
        int n=s.size();
        while(j<n){
            while(j<n&& s[j]==' ') j++;
            while(j<n&& s[j]!=' '){
                s[a]=s[j];
                a++;j++;
            }
            while(j<n&& s[j]==' ') j++;
            if(j<n) s[a++]=' ';
            //cout<<s<<endl;
        }
        s=s.substr(0,a);
        return s;
    }
};

/*

试一下吧，按照基操搞一遍 ，冲鸭； 就temp保存单词，倒着搜索单词， 然后s=s+temp+"";
思路2: 全部反转一遍，然后按照 单独翻转单词
    s.erase(s.begin() + idx, s.end());  //s 释放字符串 从 a 到 b
    reverse(s.begin(), s.end());
 private void reverse(char[] s_arr, int i, int j) {
        while (i < j) {
            char t = s_arr[i];
            s_arr[i++] = s_arr[j];
            s_arr[j--] = t;
        }
    }
然后官方好狗啊，官方居然还给了一个 用api的 
c++ 的字符串流学习：
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+temp+ans;
        }
        if(ans!="")
            ans.erase(ans.begin());
        return ans; 
    }
};
*/
