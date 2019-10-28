//空格忽略、正负号保留、首位忽略0、连续数字（中间无空格）到字符停止、首有效字符非数字输出0、超范围输出最大值/最小值。
//思路：int i =0在最开始判断空格和符号，符号位和数字的组合Int flag=1相乘，之后的while（i《）再if判断数字。
//注意细节


class Solution {
public:
    int myAtoi(string str) {
        int n=str.size();
        long res=0;
        int flag=1; //符号位相乘 后期
        int i=0;  //先解决首位空格 和 符号 问题
        while(str[i]==' ')
            i++;
        if(str[i]=='+'||str[i]=='-')
        {
            if(str[i]=='-')
                flag=-1;
            i++;
        }
        
        while(i<n )  //while控制数字位
        {
            if(str[i]<='9'&&str[i]>='0')
            {
                int temp=str[i]-'0'; //一定要，准备转换为int
                i++;
                if(res<INT_MAX) //防止res 无法表示溢出
                    res=res*10+temp;
                else
                    break;
            }
            else  //输出为字符
                break;
        }
        // 考虑超范围问题
        if(int(res)==res)
            return {res*flag};
        //if(int(res)!=res && res*flag>0)
        //    return 2147483647;
        else if(int(res)!=res)
            return flag>0?INT_MAX:INT_MIN;
        else 
           return 0;
    }
};
