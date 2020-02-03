//75、颜色分类：无序数组，红白蓝为012，排序要求原地/不用排序函数
//思路：一趟统计0 1 2个数，一趟赋值；更简单要一趟扫描的话。就搜索一遍。i放0，j放2。错误，这样j的值还没有搜索到就没有了。怪不得要用交换
//荷兰国旗问题，三路快排思路：cur搜索一遍，p0是0后面，p2是2前面但是用交换表达。若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。
若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。
若 nums[curr] = 1 ：将指针curr右移。


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,cur=0;
        while(cur<=r) //change 0  change 2 
        {
            if(nums[cur]==0)
            {
                swap(nums[l],nums[cur]);
                l++;
                cur++;
            }
            else if(nums[cur]==2)
            {
                swap(nums[r],nums[cur]);
                r--;
            }
            else
            {
                cur++;
            }
        }
    }
};
//好慢啊，运行为啥这么满，这才两趟不到扫描
//他们用的是交换，然后就可以 一趟实现了
//直接赋值是错的，这样后面的值就没有了。
/*
void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        for(int i=0;i<r;i++) //放 0 和 2，然后最后中间放1
        {
            if(nums[i]==0)
            {
                nums[l]=0;
                l++;
            }
            else if(nums[i]==2)
            {
                nums[r]=2;
                r--;
            }
        }
        l--;r++;
        cout<<l<<r;
        while(l<r)
        {
            nums[l]=1;
            l++;
        }
    }
*/
