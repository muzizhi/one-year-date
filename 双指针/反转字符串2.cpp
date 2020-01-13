//541、反转字符串2:字符串和k输入，每2k个数一组，反转每组前k元素。不够翻剩余。
//思路：一到k个数双指针反转，然后空k个数；继续操作最后一组判定不够也翻转。主要是while/for的联系，如何隔k个翻转k个

class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.empty()) return s;
        //for(int i=0;i<s.size();i=i+2k) //对于每一个要调整的2k范围
        for(int i=0;i<s.size();i=i+2*k)
        {
            int m=i,n=i+k-1;
            if(n>=s.size()) //最后一部分
            {
                n=s.size()-1;
            }
            while(m<n) //调整k部分
            {
                char temp=s[n];
                s[n]=s[m];
                s[m]=temp;
                m++;n--;
            }
        }
        return s;
    }
};
/*就是暴力，循环还可以
        count++;
        while(i<n) //从头找一遍
        {
            for(int i=0+count*2k;i<k+count*2k;i++)
            {
                reverse（）//while
            }
            count++;
        }
*/
