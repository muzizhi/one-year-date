//对于给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。注意防止溢出
//思路：x mod 10=个位数 再res*10，x/10为剩余的数。循环操作得到反转。
class Solution {
public:
    int reverse(int x) {
       // if(x==-pow(2,31))
       //     return 0; 不行，貌似超出的很多，不止这一个
       // int res=0;
        long res=0;
        while(x!=0)
        {
            res=x%10 +res*10;
            x= x/10;
        }
        if(int(res)==res)
            return res;
        else 
            return 0;
    }
};
