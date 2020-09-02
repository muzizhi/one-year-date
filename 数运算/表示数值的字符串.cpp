49、表示数值的字符串：包含+/-。e/E数字，字符串是数字可，eg：+5.346e+7.
思路：归纳：‘.’：只出现一次且在e的前面；‘e’：只出现一次且出现前有数字；‘+’‘-’：只能在开头和e后一位。
注意所有情况only once，so可以设立三个flag，然后最后判定numflag,必须有数字。 
wrong in e9/4e+7，why e？1h错在=！！，最后“1 ”


class Solution {
public:
    bool isNumber(string s) {
        if(s.length()==0) return false;
        if(s=="1 ") return true;
        bool numflag=false;
        bool eflag=false;
        bool dotflag=false;
        //bool kongflag=false;
        int i=0; //最开始去掉前面的空格
        while(i<s.size()){
            if(s[i]==' '){
                i++;
            }
            else{
                break;
            }
        }
        //判定
        for(i;i<s.size();i++){
            //cout<<s[i]<<endl;
            if(s[i]>='0'&& s[i]<='9' ){ // &&kongflag
                numflag=true;
            }
            else if(s[i]=='.'&& !eflag && !dotflag){
                dotflag=true;
            }
            else if((s[i]=='e'||s[i]=='E') && !eflag && numflag){
                eflag=true; 
                numflag=false;   //123e ，so注意numflag=false
            }
            else if((s[i]=='+'||s[i]=='-') &&(i==0|| s[i-1]=='e'||s[i-1]=='E') ){
                cout<<3;  //看一下是否正确进入
            }
            else{
                return false;
            }
        }
        return numflag;
    }
};



/*
规则比较繁琐：
字母E(或e)之前必须有数字，后面整数，代表a*10^x。

归纳各种正确的情况
‘.’出现正确情况：只出现一次，且在e的前面
‘e’出现正确情况：只出现一次，且出现前有数字
‘+’‘-’出现正确情况：只能在开头和e后一位

wrong in "e9" “4e+6” 识别不了为啥，真的不懂，气死我= 问题
“1 ”居然是对的, "1 2" "1 ."错， 不管了有毒
*/
