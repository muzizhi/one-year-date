//回文数判断，负数不是，整数121 true，20 flase。注意溢出逆转整数
//思路：我的是整数直接反转，注意溢出，int（long）=原数比较。
//官方注意溢出提出了另一种思路，比较一半，然后前后对应看。当原始数字小于反转后的数字时=处理了一半。如12321/1221=12  321/ 12  12

class Solution {
public:
    bool isPalindrome(int x) {
        long res=0;
        int y=x;
        if(x<0)
            return false;
        while(x>=1)
        {
            int temp=x%10;
            res=res*10+temp;
            x=x/10;
        }
        if(int(res)==y)
            return true;
        else
            return false;
    }
};
