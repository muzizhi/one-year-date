//差点被气死，被一个easy搞了三小时
//67、二进制求和：给定两个二进制字符串，返回他们的和，“1010”+ “1011”=“10101”
//思路：有的转数字了（溢出问题），有的采用异或思路。异或=尾数的值
//我的整体思路：补0等长好对应加，从后向前算，满2进1，注意最前位加和carry。


class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        string c;
        int carry=0;
        if(n1<n2) //对应字符串补0 对齐,
            a.insert(0,n2-n1,'0');  
        if(n1>n2)
            b.insert(0,n1-n2,'0');
        //for(int i=n1-1;i>=0;i--) //二进制相加,因为这个搞了 2个小时
        for(int i=a.size()-1;i>=0;i--)
        {
            int x= a[i]-'0';
            int y= b[i]-'0';
            int sum=x+y+carry;
            if(sum>=2)
            {
                //c[i]=sum-2+'0';  //输出错误，怀疑 固定了c【i】长度
                c.insert(0,1,sum-2+'0');// 加不加0？要加，str存的其实不是1，是xx
                carry=1;
            }
            else
            {
                c.insert(0,1,sum+'0');
                carry=0;
            }         
        }
        if(carry==1) //最前面的多一位
            c.insert(0,1,'1');
        return c;
    }
};

