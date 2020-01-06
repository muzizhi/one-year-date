//231、2的幂：判断一个数是否是2的幂
//思路：如果一个数一直被2除，直到结果为1是。ok否则不是。
//其他思路：1左移动30位得到最大的2 幂，整数ok就OK。ps如果二进制n+补码=源码。

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0) return false;
        while(n%2==0)
        {
            n=n/2;
            if(n==1)
            return true;
        }
        return false;
    }
};

/*
同理，可以采用位运算符。
&运算，同1则1。 return (n > 0) && (n & -n) == n;

或者如果最大的那个数 能整除n，那么就是2的幂
移位运算：把二进制数进行左右移位。左移1位，扩大2倍；右移1位，缩小2倍。 return (n>0) && (1<<30) % n == 0;
*/
