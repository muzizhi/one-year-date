//最长公共前缀：编写一个函数来查找字符串数组（所有输入只包含小写字母 a-z ）中的最长公共前缀。如果不存在公共前缀，返回空字符串 “”。
//先求字符串最长长度，j指针 while循环。对于字符串个数 i指针，for 循环每个跟第一个比较，如果i=n，j++保存公共字符，否则break。
//简单题，划水了


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int j=0,i,max=0;
        int n=strs.size();
        
        for(int k=0;k<n;k++)  //求单个字符串最长长度
        {
            if(max<strs[k].size())
                max=strs[k].size();
        }
        
        while(j<max)  //单个字符串最长长度
        {
            for(i=1;i<n;i++) //后面所有跟第一个字符串比较，i指有几个字符串
            {
                if(strs[i][j]!=strs[0][j])
                {
                    break;
                }
                //cout<<"i="<<i<<endl;
            }
            //cout<<i<<endl;  //莫名奇妙多一位比上一个i,应该是++了
            //if(i==n-1)
            if(i==n)
            {
                ans=ans+ strs[0][j];
                j++;
            }
            else 
                break;
        }
        return ans;
    }
};
