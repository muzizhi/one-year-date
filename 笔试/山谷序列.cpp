//山谷序列，不知道为啥一个都不对，案例过来，修改了hash不知道怎么样

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <iomanip>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;
#define debug puts("======================")

int rightnum(vector<int> a,int t){ 
    vector<int> res;
    res.push_back(a[t]);
    int j=1;
    for(int i=t+1;i<a.size();i++){
        if(a[i]>res[j]){
            j++; res.push_back(a[i]); continue;
        }
        if(a[i]<a[t]) continue;
        int temp=j;
        while(a[i]<res[temp]){
            temp--;
        }
        res[temp+1]=a[i];
    }
    return res.size();
}
int leftnum(vector<int> a,int t){
    vector<int> res;
    res.push_back(a[t]);
    int j=1;
    for(int i=t-1;i>=0;i--){
        if(a[i]>res[j]){
            j++; res.push_back(a[i]); continue;
        }
        if(a[i]<a[t]) continue;
        int temp=j;
        while(a[i]<res[temp]){
            temp--;
        }
        res[temp+1]=a[i];
    }
    return res.size();
}
int main() 
{
    int T;
    scanf("%d",&T);
    while(T--){
        unordered_map<int,int> hash;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> l;
        vector<int> r;
        for(int i=0;i<n;i++){
            if(hash.count(a[i])){
                int temp=hash[a[i]];
                l.push_back(temp);
                r.push_back(i);
                hash[a[i]]=i;//更新存储值对应下标
            }
            hash[a[i]]=i; //存储值对应下标
        }
        if(l.size()==0){
            cout<<0<<endl; continue;
        }
        int res=0;
        for(int i=0;i<l.size();i++){
            int t=l[i];
            int l=leftnum(a,t);
            t=r[i];
            int r=rightnum(a,t);
            cout<<t<<" "<<l<<" "<<r<<endl;  //返回 那个取值下标，左 和右边个数
            int temp=min(l,r);
            res=max(res,temp);
        }
        cout<<res<<endl;
    }
    return 0;
}

//比较麻烦，1求解较小的x和相对的x（hash查找） 2、求解x前和 x后各有几个递增的可能，取min*2
//待定,一会继续2
