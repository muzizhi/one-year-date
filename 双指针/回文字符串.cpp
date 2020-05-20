125、验证回文串：忽略空格标点，忽略大小写，仅看字母/数字
思路：双指针，if字母a=a|a=a+32；数字=数字。尝试0p之间ascii码相差32，先统一转。


680、验证回文字符串2：s中删除一个字符，能否回文，true/false
思路：双指针，不对删除1个，对应到终点，错cupupucu。解决：尝试后面第二个也相等，但是有可能超过，成功。
官方思路双指针加迭代，到不同分别迭代两个子串看true。

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0) return true;
        int i=0,j=n-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++; continue;
            }
            if(!isalnum(s[j])){
                j--; continue;
            }
            if(s[i]==s[j]||tolower(s[i])==s[j]||s[i]==tolower(s[j])){
                i++; j--;
            }
            else return false;
        }
        return true;
    }
};

/*
思路：双指针，if字母a=a|a=a+x；数字=数字。尝试，不行 0p 之间相差32，大小写也是32，先把大写转小写
主要是：大小写转换  "."
记一笔 c++的几个内置函数
islower(char c) 是否为小写字母
isuppper(char c) 是否为大写字母
isdigit(char c) 是否为数字
isalpha(char c) 是否为字母
isalnum(char c) 是否为字母或者数字
toupper(char c) 字母小转大
tolower(char c) 字母大转小

统一转成大写：ch & 0b11011111 简写：ch & 0xDF
统一转成小写：ch | 0b00100000 简写：ch | 0x20
c++的api：
        while(i<=j){
            if(!isalnum(s[i])) {i++;continue;}
            if(!isalnum(s[j])) {j--;continue;}
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;j--;
        }
*/

