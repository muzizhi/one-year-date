4、寻找两个正序数组的中位数：两个有序数组，联合返回中位数，时间o(log(m+n))

思路：那是不是两个数组合并的意思呢，中位数直接返回最中间的，但是复杂度高了
依靠2分，类似于找数组中 第k个元素，本来想每个都取对应一半，但是不好减，之前都是n，现在m、n 
那就按照官方思路每个比较k/2元素，存在赋值。如果k1《k2，不在k1前k/2个，num1后移动，k-k/2
如果一个没有，那么可以设为超大值，因为长的那个数组k/2肯定不对，不够啊





class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=m+n+1;
        if((m+n)%2==1){
            return findk(nums1,0,nums2,0,k/2); //7 k=the num 4
        }
        else{
            double x=findk(nums1,0,nums2,0,k/2);
            double y=findk(nums1,0,nums2,0,(k+1)/2);
            cout<<x<<y<<(x+y)/2<<endl;
            return (x+y)/2; 
            //6 k=(3+4)/2   wrong 3: (3+4)/2 =3???
        }
    }
    int findk(vector<int>& nums1, int l1,vector<int>& nums2,int l2,int k){
        int m=nums1.size(),n=nums2.size();
        //cout<<"l1="<<l1<<m<<k<<endl;
        if(m==l1) return nums2[l2+k-1];  
        if(n==l2) return nums1[l1+k-1];
        if(k==1) return min(nums1[l1],nums2[l2]);  //wrong 2 三个判定条件

        int index1=min(l1+k/2-1,m-1);// 都要-1，因为int 从0开始
        int index2=min(l2+k/2-1,n-1);
        //cout<<index1<<index2<<k<<endl;

        if(nums1[index1]<=nums2[index2]){
            return findk(nums1,index1+1,nums2,l2,k-index1+l1-1);  //wrong k-k/2
        }
        else{
            return findk(nums1,l1,nums2,index2+1,k-index2+l2-1);
        }
    }
};

/*
总感觉以前做过，需要2分吗
那是不是两个数组合并的意思呢，中位数直接返回最中间的，但是复杂度高了
依靠2分，类似于找数组中 第k个元素，本来想每个都取对应一半，但是不好减，之前都是n，现在m、n 
那就按照官方思路每个比较k/2元素，存在赋值。如果k1《k2，不在k1前k/2个，num1后移动，k-k/2
1 3 3 
1 2 3 4 
特殊情况考虑，如果没有k/2个元素，那最后一个元素替补吧.
wrong 1: k-k/2
wrong 2;

in fact,如果一个没有，那么可以设为超大值，因为长的那个数组k/2肯定不对，不够啊


*/
