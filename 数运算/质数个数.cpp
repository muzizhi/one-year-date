//204、计数质数：输入n，统计所有小于非负整数 n 的质数的数量。
//思路：脑袋空白，质数的判定o（n），所有数遍历o（n2）。优化：对于n，找（2，根n）范围就够了；这样还是冗杂计算很多，如果逆向考察更容易优化。
//官方优化思维，如果x是质数，其倍数都不是。找最后依旧为true输出。并且可以更优，外层筛选x判定（2，根n），筛选倍数y从2x换成x^2，去掉x（<y）*y的部分。


class Solution {
public:
    int countPrimes(int n) {
        //vector<bool> res(n,true); //先默认都是质数
        if(n==1||n==0||n==2)
            return 0;
        int count=1;
        for(int i=3;i<n;i++) //尝试偶数先标，然后只搜索奇数，还是超时;更改count一直超时，算了吧
        {
            bool a=true;
            if(i%2==0)
                a=false;
            for(int j=3;j*j<=i;j=j+2)
            {
                if(i%j==0)
                {
                    a=false;
                    break;
                }
            }
            if(a==true)
            count++;
        }
        return count;
    }
};


/*下面这个不超时，窒息，一样思路，人家更优
    if(n < 3)
        return 0;;
    //从3开始验算，所以初始值为1（2为质数）。
    int count = 1;
    for (int i = 3; i < n; i++){
        //当某个数为 2 的 n 次方时（n为自然数），其 & (n - 1) 所得值将等价于取余运算所得值
        //*如果 x = 2^n ，则 x & (n - 1) == x % n
        //if(i % 2 == 0)
        if ((i & 1) == 0)
            continue; ;
        bool sign = true;
        //用 j * j <= i 代替 j <= √i 会更好。
        //因为我们已经排除了所有偶数，所以每次循环加二将规避偶数会减少循环次数
        for (int j = 3; j * j <=i; j+=2){
            if (i % j == 0){
                sign = false;
                break;
            }
        }
        if (sign)
            count++; ;
    }
    return count;

其他思路：
1、Sieve of Eratosthenes/厄拉多塞筛法：顺序遍历，每取得一个数（排除0、1），如果将它所有的倍数（排除0、1、本身）都清除，那么，剩下的数是不是必为素数
int countPrimes(int n) {
    int count = 0;
    //初始默认所有数为质数
    vector<bool> signs(n, true);
    for (int i = 2; i < n; i++) {
        if (signs[i]) {
            count++;
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                signs[j] = false;
            }
        }
    }
    return count;
}

作者：magicalchao
链接：https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-bao-li-fa-ji-you-hua-shai-fa-ji-you/

2、更优化。外层到i^2停止， 内层考虑x的倍数前面的已经乘过了，就从更大的开始。

int countPrimes(int n) {
    boolean[] isPrim = new boolean[n];
    Arrays.fill(isPrim, true);
    for (int i = 2; i * i < n; i++)  //外层的 for 循环也只需要遍历到 sqrt(n)，
        if (isPrim[i]) 
            for (int j = i * i; j < n; j += i)  //j 从 i 的平方开始遍历，而不是从 2 * i 开始。
                isPrim[j] = false;
    
    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrim[i]) count++;
    
    return count;
}
我超时的原版：vector<bool> res(n,true); //先默认都是质数
        res[0]=false;
        res[1]=false;
        int count=1;
        for(int i=3;i<=n;i++) //尝试偶数先标，然后只搜索奇数，还是超时;更改count一直超时，算了吧
        {
            if(i%2==0)
                res[i]=false;
            for(int j=3;j*j<=i;j=j+2)
            {
                if(i%j==0)
                {
                    res[i]=false;
                    break;
                }
            }
            if(res[i]==true)
            count++;
        }
        return count;

*/
