//两整数之和：不使用运算符 + 和 -  ，计算两整数  a 、b  之和 5+7=12。
//思路：两个整数a, b; 二进制考虑a ^ b（异或10-1）是无进位的相加； a&b（相与11-1）得到每一位的进位；
//让整体异或的结果与整体进位不断的异或和再进位，到进位为0；注意负数溢出保护，对于进位c需要左移一位，保证高位；

class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            //int carry = (a&b)<<1; //错误，负数处理失败
            int carry = ((unsigned int ) (a & b))<<1 ; //对有符号左移的溢出保护处理，强制转换无符号位
            a=a^b;
            b=carry;
        }
        return a;
    }
};
