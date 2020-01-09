//344、反转字符串：字符数组输入，输出逆序的字符数组，要求原地修改，空间o（1）
//思路：每次将最后一个字符添加到第i个，后面删除最后一个。
//也可以使用双指针法，不调用函数，左0 右n，交换位置向中间看齐

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char temp=s[n-1];
            s.insert(s.begin()+i,1,temp);  //数组插入 char
           // s.erase(n-1,n);// 删除从n开始的1个字符,数组删除
           s.erase(s.end()-1);  
        }
    }
};
//也可以使用 双指针法，不调用函数，左0 右n，交换位置向中间看齐。
