//166、分数转小数：给定两个整数，分子和分母，以字符串形式返回小数。如果小数部分为循环小数，循环的部分括在括号内。如2/3=“0.(6)”，考虑正负、溢出、循环
//思路：设定float直接除保存分数，转为字符；循环的判定，被除数重复，可以用哈希表。
//实践，直接用浮点数除法没法保存，必须一位一位计算。Mod*10/除数继续。
//细节太多了，密密麻麻


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
            return "0";
        //int sign=numerator*denominator>=0?1:-1; //保存符号位,超范围，窒息-2147483648
        // 窒息7/-12 =0,那我用乘法
        int num=numerator>=0?1:-1;
        int den=denominator<0?-1:1;
        int sign=num*den>=0?1:-1;
        long long a=abs(long(numerator));  //防止溢出，采用 long
        long long b=abs(long(denominator));
        string res=to_string(a/b);
        if(sign==-1)
            res="-"+res;
        if(a%b==0)
            return res; //如果整除，输出
        res=res+".";
        unordered_map<long,int> hash;// 存储循环，mod出现在第几位置,找过去加（
        string s;
        int count=0;
        while(a%b!=0)
        {
            if(hash.count(a%b)) //如果mod已经出现过,注意插入是hash对应的位置
            {
                //s=insert(hash[a%b],'(');  双引号这里居然是
                s.insert(hash[a%b],"(");
                s=s+")";
                return res+s;
            }
            hash[a%b]=count;
            long mod=a%b*10; //类型要设为long，要不然溢出
            s=s+to_string(mod/b);
            a=mod;
            cout<<mod/b<<endl;
            count++;
        }
        //string t="123456";
        //cout<<t.insert(2,"("); //观测 insert使用规则，输出12(3456
        return res+s;

        
    }
};

/*
我的思想：先求出小数，然后思考循环保留；
这种题有几种易错点：
正负号问题 --先保存
加小数点的情况,--整除不加
小数部分,如何判断是否开始循环了--哈希
考虑正负的溢出 -- 用长整型

用哈希表存储的 没看太复杂
首先判断结果正负，sign=(n*d<0), true表示有符号即负数； 然后对被除数、除数求绝对值n,d，可以不进行分数约分（即求最大公约数），模拟手工计算除法，并用哈希集合存储当前被除数n是否出现过； 如果曾经出现，则确定是循环小数； 最后将正负号+整数部分+小数点+小数部分返回。 其中可以使用哈希映射存储<被除数,小数部分下标>，确定循环部分的区间。

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign=(1L*numerator*denominator<0L);
        long n=labs((long)numerator), d=labs((long)denominator), i;
        string integer((sign?"-":"")+to_string(n/d)), fraction;
        unordered_map<long,long> dict;
        for(n=(n%d)*10, i=0; n && !dict.count(n); n=(n%d)*10){
            dict[n]=i++;
            fraction.push_back('0'+n/d);
        }
        if(!n) return integer+(fraction.length()?"."+fraction:"");
        return integer+"."+fraction.substr(0,dict[n])+"("+fraction.substr(dict[n])+")";
    }

*/
