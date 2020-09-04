36、统计数字在升序数组的次数：统计一个数字在升序数组中出现的次数。
思路：有序，所以直接2分查找就好了, 找上界l 下界r.第一个while（<k）返回l代表第一个=k,第二个while(<=k)，代表第一个大于k的。Wrong in 没有大于k的数，so r=n/ok。



class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l=0,r=data.size();
        while(l<r){
            int mid=(l+r)/2;
            if(data[mid]<k){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int left=l;
        l=0,r=data.size();
        while(l<r){
            int mid=(l+r)/2;
            if(data[mid]<=k){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        int right=l; //返回 大于k的第一个值，没有 1233333，找3，两个r直接取到n
        cout<<left<<" "<<right<<endl;
        return right-left;
    }
};

//有序，所以直接2分查找就好了, 找上界l 下界r.第一个while（<k）,第二个while(<=k)
//一次貌似找不完，分两次去找。 
/*
int GetNumberOfK(vector<int> data ,int k) {
        auto l = lower_bound(data.begin(), data.end(), k);
        auto r = upper_bound(data.begin(), data.end(), k);
        return r - l;
    }
*/
