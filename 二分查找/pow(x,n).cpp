//50、pow（x，n）：求浮点数x的n次方，都可能为负（2^-2 = 1/2 2 = 1/4 = 0.25）
//思路：对于浮点数x判断正负，对于n判断正负，累乘。超时了，要不就缩小计算，3^8=(3^2)^4
//官方思考就是上面，但是每个范围都缩减。


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1; //要保留5位小数吗，貌似自动等了
        if(n==1) return x;
        if(n==-1) return 1/x;
        double half=myPow(x,n/2);;
        if(n%2==0)
        {
            return half*half;
        }
        if(n%2!=0 && n<0)
        {
            return half*half*1/x; //如果x为负，应该* 1/x
        }
        else return half*half*x;
    }
};


/*
利用二分法，降低复杂度到 o（logn）
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) { return 1; }
        if (n == 1) { return x; }
        if (n == -1) { return 1 / x; }
        double half = myPow(x, n / 2);
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};

作者：frank588
链接：https://leetcode-cn.com/problems/powx-n/solution/qing-xi-jian-dan-de-dan-han-shu-di-gui-wu-lei-xing/


我自己的原来版本--超时
public:
    double myPow(double x, int n) {
        if(n==0) return 1; //要保留5位小数吗，貌似自动等了
        double res=1;
        if(n<0)
        {
            x=1/x; //可以直接用不定义吗，yes
            n=-n;
        }
         for(long i=1;i<=n;i++)  //long 设置i++超范围，运行超时
            res=res*x;
        
            
        return res;
    }
*/
