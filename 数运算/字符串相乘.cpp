//43、字符串相乘：乘积c也要字符串形式，输入a、b不能整体转成整数
//思路：有点难啊，输入不能整体转。按照运算就是a 每一位乘 b末尾，保留进位。有点麻烦，然后注意999*999，
//乘积对应位数是i+j位，可以先用int型数组++存储乘积每一位对应的值，每行结束考虑最后一个数进位恢复。再把每一个数（可》10）转换成字符型表示。
//主要考虑情况：乘数为0；乘数为个位*个位；乘数为超大数*大数。

class Solution {
public:
    string multiply(string num1, string num2) { //123 *45
        if(num1=="0"||num2=="0")
            return "0";
        int carry=0;
        string res;
        int n=num2.size()+num1.size()-1;
        vector<int> mul(n); //res 的整数版，方便每一个位的相加,超10后续处理，最多n1+n2-1位
        for(int i=num2.size()-1;i>=0;i--) //45
        {
            for(int j=num1.size()-1;j>=0;j--) //123
            {
                int temp=(num1[j]-'0')*(num2[i]-'0')+carry;
                carry=temp/10;
                mul[i+j]+=temp%10; //得到了对应乘积的每一位置，不过是int ，可能超10
                
            }
            if(carry!=0&&i-1>=0)  //每一行乘积完最后一个 mul【】如果有进位处理
            //mul[0]+=carry*10;   恢复每一行乘积完最后一个 mul【】对应的值，可能++大于100 难搞
            {
                mul[i-1]+=carry;
                carry=0;
            }
        }
        if(carry!=0)  //乘积完最后一个 mul【】如果有进位处理
            mul[0]+=carry*10;
            carry=0;

        for(int i=n-1;i>=0;i--)  //从个位数 开始把整数（》10）转换 成字符
        {
            mul[i]=mul[i]+carry;
            carry=mul[i]/10;
            cout<<mul[i]<<carry<<endl;
            int temp=mul[i]%10;
            res.insert(0,1,temp+'0');
        }
        if(carry!=0)
        res.insert(0,1,carry+'0');
        return res;
    }
};
