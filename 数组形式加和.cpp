//数组形式的加和：给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
//思路：a可能超大，所以不用思考数组转整数。k转字符串，加和数组，输出数组求逆序。
//换种方式：k不转了，直接整数求个位一点点加
//或者机智的全部加和数组，如 1 3 4 5+ k=227,计算5+227=232，23作为新进位，2保留。


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        string str=to_string(K);  //k转成字符串输出
        int i=A.size()-1,j=str.size()-1;
        int count=0;
        vector<int> b;
        while(i>=0||j>=0 || count>0) //计算 数组 + 字符串 =数组
        {
            int sum=0;
            if(i>=0) sum +=A[i];
            if(j>=0) sum=sum+str[j]-'0';
            sum=sum+count;  //整体k 直接加
            //cout<<sum<<endl;
            count= sum/10;
            b.push_back(sum%10);
            i--;
            j--;
        }
        reverse(b.begin(),b.end()); //转顺序 数组
        return b;           
    }
};

/* 不转换k，推荐，挺有意思的思路
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
       // string str=to_string(K);  //k不转成字符串输出，直接整数计算
        int i=A.size()-1;
        int count=K;
        vector<int> b;
        while(i>=0|| count>0) //计算 数组 + 字符串 =数组
        {
            int sum=0;
            if(i>=0) sum +=A[i];
            sum=sum+count;  //整体k 直接加
            count= sum/10;
            b.push_back(sum%10);
            i--;
        }
        reverse(b.begin(),b.end()); //转顺序 数组
        return b;           
    }
*/
