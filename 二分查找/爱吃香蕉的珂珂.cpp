875、爱吃香蕉的珂珂：n堆，每小时1堆吃《k，h小时吃完所有最小速度k。
思路：k速度能吃完吗，然后速度k二分找（1-max堆值）。尝试，成功，二分也简化


class Solution {
public:
//k速度内 h小时是否可以吃完
bool timecan(vector<int> p,int k, int h){
	//k 如果 mid-1=0报错
    if(k==0) return false;
    int cnt=0;
    for(int i=0;i<p.size();i++){
        int temp=p[i]/k;
        if(p[i]%k!=0) temp++;
        cnt+=temp;
    }
    //cout<<k<<"速度吃完时间:"<<cnt<<endl;
	if(cnt<=h) return true;
	else return false;

}
      //k 进行二分，判定time是否符合条件
  int minEatingSpeed(vector<int>& piles, int H) {
    int maxn=0;
    for(int i=0;i<piles.size();i++){
        maxn=max(maxn,piles[i]);
    }
    int left=1,right=maxn;
    int ans=1;
    /*
    while(left>0&&left<=right){  //	循环很有可能走不出去，加上=
    	int mid=(left+right)/2;
    	if(timecan(piles,mid,H)&&!timecan(piles,mid-1,H)){
    		ans=mid; 
    		//cout<<ans<<endl;
    		break;
    	}
    	if(timecan(piles,mid,H)&&timecan(piles,mid-1,H)){
    		right=mid-1;
    	}
    	if(!timecan(piles,mid,H)&& !timecan(piles,mid-1,H)){
    		left=mid+1;
    	}
    }*/
    while(left<right){  //	循环很有可能走不出去，加上=
    	int mid=(left+right)/2;
    	if(!timecan(piles,mid,H)){
    		left=mid+1;
    	}
    	else{  //不中右移动，中先放在mid上
    		right=mid;
    	}
    }
    return left;
   }
};


/*
二分的可以更简单：试试看输出啥
int lo = 1, hi = pow(10, 9);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, H, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;

*/
