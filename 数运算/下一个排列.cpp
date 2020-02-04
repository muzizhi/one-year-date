31、下一个排列：字典序列123输出132，就是连起来最近比它大的数，无则返最小序列。
思路：要求原地修改。倒着找5 2 3 1- 5 3 1 2。j2《i3，31放2前面用插入试试。错误如[0,5,4,3,2,1]，下一个是[1,0,2,3,4,5]。所以还是j0《i1，交换0和1，然后排序j+1-n；j错。
正确的思路：amazing如[0,2,4,3,2,0]从右边找一个i，比i+1小「因为后面递减」，选择好正确的j2，然后找到后面最小的比j3大的值交换，再排序。

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        for(i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
               // i--;break;  //wrong if i=1,i--=0 wrong
               break;
            }
        }  
        cout<<i;
        if(i==0)
            reverse(nums.begin(),nums.end());
        else{
            i--;
            int min=i+1; 
            for(j=i+1;j<n;j++) //找到i 和要交换的比i 大一点点的元素
            {
                if(nums[j]<nums[min] && nums[j]>nums[i])
                {
                    min=j;
                }
            }
            swap(nums[min],nums[i]);  //交换真实的
            sort(nums.begin()+i+1,nums.end()); //后续排序
        }
    }
};

/* 5 2 3 1- 5 3 1 2
找一个比最右边小的数据 。用插入试试
错误，如[0,5,4,3,2,1]，下一个是[1,0,2,3,4,5]
还是要找一个比最右边小的数据 ，先交换i、j 再排序j+1-n；
void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        for(i=n-1;i>0;i--)
            for(j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    //cout<<i<<j;
                    swap(nums[j],nums[i]);
                    sort(nums.begin()+j+1,nums.end()); //后续排序
                    return;
                }
            }
        if(i==0&&j==-1)
            reverse(nums.begin(),nums.end());
    }
错误，比如[4,2,0,2,3,2,0]，应该是[4,2,0,3,0,2,2]
所以找一个第一个最小的i《i后面的数。 我找的是0 应该找2



*/
