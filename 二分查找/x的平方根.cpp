69、x的平方根：实现sqrt（x），返回整数，不要小数。
思路：很简单，判定i*i 刚超过x，返回i-1就是。或者也有人利用2分查找，返回左值。



class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        int res;
        for(long i=1;i<=x;i++){
            if( i*i>x){
                res=i-1;
                break;
            }
        }
        return res;
    }
};

/* 貌似也可以用2分，返回min
int mySqrt(int x) 
    {
        if(x == 1)
            return 1;
        int min = 0;
        int max = x;
        while(max-min>1)
        {
            int m = (max+min)/2;
            if(x/m<m)
                max = m;
            else
                min = m;
        }
        return min;
    }
*/
