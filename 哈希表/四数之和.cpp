//18、四数之和：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得和与 target 相等？
//找出所有满足条件且不重复的四元组。注意：答案中不可以包含重复的四元组。
//思路：也是双指针的思路。先排序，前两个a、b指针在左边，然后c从b+1向右，d最末向左，相遇结束。a<b<c<d，加和为target。


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)
            return {};
        sort(nums.begin(),nums.end()); //排序
        int n=nums.size();
        for(int a=0;a<n;a++) //记住遇见一样的，要跳过
        {
            //if(nums[a]==nums[a+1]) //错误，a到最大的时候，不存在a+1
            if(a>0&&nums[a]==nums[a-1])
                continue;
            for(int b=a+1;b<n;b++)
            {
                //if(nums[b]==nums[b+1])
                if(b>a+1&&nums[b]==nums[b-1])
                    continue;
                int target_1=target-nums[a]-nums[b];
                //for(int ) 指针的游走更改，用while比较合适
                int c=b+1,d=n-1;
                while(c<d)
                {
                    if(nums[c]+nums[d]==target_1)
                    {
                        vector<int> temp={nums[a],nums[b],nums[c],nums[d]};
                        res.push_back(temp);
                        cout<<a<<b<<c<<d<<endl;
                        while(c<d&&nums[c+1]==nums[c]) c++;
                        while(c<d&&nums[d-1]==nums[d]) d--;
                        cout<<c<<d<<endl;
                        c++; d--; //差点忘记了
                    }
                    else if(nums[c]+nums[d]<target_1)  //必须else，要不然c可能超范围 编译失败
                        c=c+1;
                    else
                        d=d-1;
                }
            }
        }
        return res;    
    }
};


/*
java双指针，性能很优，加入筛选操作 固定第一个a，如果最小的都大，或者最大的都小，a不可能。
public List<List<Integer>> fourSum(int[] nums,int target){
        
        List<List<Integer>> result=new ArrayList<>();
        //当数组为null或元素小于4个时，直接返回
        if(nums==null||nums.length<4){
            return result;
        }
        Arrays.sort(nums);
        int length=nums.length;
        //定义4个指针k，i，j，h  k从0开始遍历，i从k+1开始遍历，留下j和h，j指向i+1，h指向数组最大值
        for(int k=0;k<length-3;k++){
            if(k>0&&nums[k]==nums[k-1]){
                continue;
            }
            //获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏
            int min1=nums[k]+nums[k+1]+nums[k+2]+nums[k+3];
            if(min1>target){
                break;
            }
            //获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略
            int max1=nums[k]+nums[length-1]+nums[length-2]+nums[length-3];
            if(max1<target){
                continue;
            }
            //第二层循环i，初始值指向k+1
            for(int i=k+1;i<length-2;i++){
                if(i>k+1&&nums[i]==nums[i-1]){
                    continue;
                }
                int j=i+1;
                int h=length-1;
                /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏，忽略
                int min=nums[k]+nums[i]+nums[j]+nums[j+1];
                if(min>target){
                    continue;
                }
                /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略
                int max=nums[k]+nums[i]+nums[h]+nums[h-1];
                if(max<target){
                    continue;
                }
                /*开始j指针和h指针的表演，计算当前和，如果等于目标值，j++并去重，h--并去重，当当前和大于目标值时h--，当当前和小于目标值时j++
                while (j<h){
                    int curr=nums[k]+nums[i]+nums[j]+nums[h];
                    if(curr==target){
                        result.add(Arrays.asList(nums[k],nums[i],nums[j],nums[h]));
                        j++;
                        while(j<h&&nums[j]==nums[j-1]){
                            j++;
                        }
                        h—;
                        while(j<h&&i<h&&nums[h]==nums[h+1]){
                            h—;
                        }
                    }else if(curr>target){
                        h—;
                    }else {
                       j++;
                    }
                }
            }
        }
        return result;
    }
}
作者：you-wei-wu
链接：https://leetcode-cn.com/problems/4sum/solution/ji-bai-9994de-yong-hu-you-dai-ma-you-zhu-shi-by-yo/

*/
