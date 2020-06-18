393、Utf-8编码：2-4/即n字节：n个1+0/10xx/10xxx ；1字节为 0xxx，验证整数的utf8
思路：整数用二进制表示？重点在于如何提取前几个。善于使用位运算，统计n个1，and判定10是几个，wrong：注意不能超过4个，也不能为0个。


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=0;
        int mask1=1<<7;
        int mask2=1<<6;
        
        for(int i=0;i<data.size();i++){
            //用位计算 求解整数前8位有几个n
            if(n==0){
                int mask=1<<7; //1000 0000
                //while(mask & data[i] ==1){  这样验证报错，貌似是java的写法
                while(mask & data[i]){
                    n+=1;
                    mask=mask>>1;
                }
                if(n==0){
                    continue;
                }
                if(n==1||n>4){
                    return false;
                }
            }
            //验证10, n次
            else{
                if(!(data[i]&mask1 && !(data[i]&mask2)) ){  //如果不是 10 开头
                    return false;
                }
            }
            n--; //比如n=3，后面就是有2个 ，所以else之外n--
        }
        cout<<n;
        if(n==0) return true;
        else return false;
    }
};



/*
整数用二进制表示，看是否有效，懵。
感觉就是严重vector第一个是啥，计为n，然后统计10数目（咋统计啊，二进制吗）
*/
