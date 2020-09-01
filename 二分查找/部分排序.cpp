面试16 部分排序：找出m，n。If m-n有序则整体有序，没有返回-1/-1。
思路：如果不想全排序。边界确定法：从左往右，更新最大值，如果i小，则（？，i）一定要排序。最后一定是右边界。
左边界： 从右往左，更新最小值，如果j大，则（j，？）一定排序，最后j找到最小值对应的左边界。注意如果l/r没修改/有序/则返回-1/-1.


class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int n=array.size();
        if(n==0) return {-1,-1};
        int maxv=array[0],minv=array[n-1];
        int left=0,right=0;
        for(int i=0;i<n;i++){
            if(array[i]>maxv){
                maxv=array[i];
            }
            if(array[i]<maxv){  //肯定有问题，这之前改
                right=i;
            }

            if(array[n-1-i]<minv){
                minv=array[n-1-i];
            }
            if(array[n-1-i]>minv){ //肯定有问题，这之后改
                left=n-1-i;
            }
        }
        if(left==0&&right==0){  //wrong，注意没修改的时候
            return {-1,-1};
        }
        return {left,right};
    }
};

/*
有点麻烦，如果不想全部排序的话，考虑一下
左      中        右
xx大    小/大     小 xxxx
要求中最小> 左最大， 中最大< 右最小
so 重点来了，从左往右，更新最大值，如果i小，则（？，i）一定要排序。最后一定是右边界
左边界： 从右往左，更新最小值，如果j大，则（j，？）一定排序，最后j找到最小值对应的左边界。
*/
