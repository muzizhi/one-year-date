
//kmp算法太难了，最后过了88
//字符串组成问题,s1and s2 的共同组成
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <iomanip>
#include<numeric>
#include<set>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;
#define debug puts("======================")
int ne[1000000];
void getnext(int l,string str){  //kmp算法
    int j=0,k=-1;
    ne[0]=-1;  //next【0】=-1，然后 k=-1/++=0 之后方便k回溯
    while(j<l){
        if(k==-1|| str[j]==str[k]){
            j++; k++;
            ne[j]=k;
        }
        else
            k=ne[k];
    }
}
int get_seg(string str){
    int l,m;
    l=str.size();
    getnext(l,str);
    m=ne[l];
    
    if(m==-1) //一直没重复的
        return l;
    else if(m==l){ //一直重复
        return 1;
    }
    else if(l%(l-m)!=0)  //l %(l-m) 感觉像是 看能分成几段 abcabcabc l=9,m=6;
        return l;
    else{
        m=l/(l-m);
        return l/m;
    }
}

int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    string res="";
    int n=s1.size();
    int m=s2.size();
    int minnum=min(m,n);
    for(int i=0;i<minnum;i++){
        if(s1[i]!=s2[i]){
            cout<<res; return 0;
        }
    }
    //如果存在，注意可能是倍数
    int a=get_seg(s1);
    int b=get_seg(s2);
    n=n/a;
    m=m/a;
    int k=__gcd(n,m);
    //cout<<a<<b<<endl;
    //cout<<k<<endl;
    for(int i=0;i<a*k;i++){
        res=res+s1[i];
    }
    cout<<res;
    return 0;
}
//先输出长度并找短的，然后短的划分，ac44，尝试比如abab，只会ab不重复，尝试89
