10、矩阵覆盖：大的2*n，用n个小的2*1的组合，有几种方法。
思路：竖着+横着，如果只竖一个，n=5，1*4（横），4/2+1=3种；3*2，3+1=4种；如果n=7,25/43/61,25=6;61=4;43款=3+1+C42；插4空横的连4/不连/连i个就从c41+..+c42，尝试，n=0出0\n=1出1；wrong，数学很麻烦，连不连也不易错，
递归考虑：if 4个就是3的所有情况后面+1竖；以及2的所有情况后面+2横，so dp(n)=dp(n-1) + dp(n-2).

class Solution {
public:
    int compu(int a,int b){ //C43 运算 4*3*2/3*2*1
        int c1=1; int c2=1;
        for(int i=1;i<=b;i++){
            c1=c1*(a-i+1);
            c2=c2*i;
        }
        return c1/c2;
    }
    int rectCover(int n) {
        int res=0;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1,b=2;
        for(int i=3;i<=n;i++){
            res=a+b;
            a=b;
            b=res;
        }
        return res;
    }
};

//2*n 的组合，用2*1，方法种类，纯数学吗，好难推
//如果n=7,25/43/61,25=6;61=4;43款=3+1+C42；插4空横的连4+不连+连一点就从c41+..+c42
/*wrong,in n=8,附上源代码
int rectCover(int n) {
        int res=1;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int i;
        for( i=2;i<n;i=i+2){
            int t1=n-i; //竖着1个的个数t1；
            if(t1==1) res+=i/2+1;
            else if(i==2) res+=t1+1;
            else{  //t1 个竖1， i/2个横的
                for(int j=1;j<=i/2;j++){
                    res+=compu(t1+1,j);
                }
            }
            cout<<res<<endl;
        }
        if(i==n) res++;
        return res;
    }
*/
