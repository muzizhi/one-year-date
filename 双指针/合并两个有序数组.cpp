//88、合并两个有序数组：将两个数组合并到第一个里面。
//思路：最开始当作字符串，新建立了一个数组，最后复制过去-太麻烦了。占用额外的空间，
//然后官方思路：从后向前走，这样不需要重新复制，i、j、t不会相互打扰。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        int i=0,j=0,t=0;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                nums3[t]=nums1[i];
                t++;
                i++;
            }
            else{
                nums3[t]=nums2[j];
                t++;
                j++;
            }
        }
        cout<<i<<j<<t;
        while(i!=m)
        {
            nums3[t]=nums1[i];
            t++;
            i++;
        }
        while(j!=n)
        {
            nums3[t]=nums2[j];
            t++;
            j++;
        }
        for(int k=0;k<m+n;k++)
        {
            nums1[k]=nums3[k];
        }
    }
       
};

/*最开始当作字符串处理了，然后发现原来要是放回原数组,慢了

方法二已经取得了最优的时间复杂度但需要使用额外空间。这是由于在从头改变nums1的值时，需要把nums1中的元素存放在其他位置。
如果我们从结尾开始改写 nums1 的值又会如何呢？这里没有信息，因此不需要额外空间。
