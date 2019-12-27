//415、字符串相加：一样的规则，输入不能整体转换，注意输入大小
//思路：先导题，作为乘积的练手。对齐补0，按照运算从后到前，挨个相加，保留进位。


class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int n1=num1.size(),n2=num2.size();
        int carry=0;
        if(n1<n2)
           // num1.insert(0,n2-n1,"0"); 双引号字符串，单引号字符
           num1.insert(0,n2-n1,'0');
        if(n1>n2)
            num2.insert(0,n1-n2,'0');
        for(int i=num1.size()-1;i>=0;i--) // string 同样下标是 0-n-1
        {
            int temp=num1[i]+num2[i]+carry-'0'-'0';
            cout<<temp<<endl;
            if(temp>=10)
            {
                carry=temp/10;
                res.insert(0,1,temp%10+'0');
            }
            else 
            {
                res.insert(0,1,temp+'0');
                carry=0;
            }
        }
        if(carry!=0)
        res.insert(0,1,carry+'0');

        return res;
    }
};
