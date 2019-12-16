//55、跳跃游戏：数组每个数字代表最大能跳步数，给定数组判定能否到底最后一个位置
//思路：贪心思路：从第一个点，能到的标true，然后之后能到的点为起点继续标，最后看最后一个元素。但是存储会超时，改进不重复赋值，每次只能到达k-新k之间true，好了。
//大佬改进存储目前到达最大步数k=max(i+nums[i],k)，但是判断什么时候能加？i<k大佬思路依据核心：如果一个位置能到达，那么它左侧所有位置都能到达。
//官方思路：动态规划，自底向上，自顶向下等复杂，可细看
//还有一个思路也不错，如果没0肯定可以，有0判断0是否能跳过（i+nums[i]>j）


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> able(n,false); //每个元素自己是否可达，判断最后可达距离是否》n
        able[0]=true;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(able[i]==true)
            {
                //for(int j=1;j<=nums[i]&&i+j<n;j++) //注意一下i+j不能大于size
                if(k<i+nums[i])  //简化，不重复赋值，过了稳的。
                {//主要利用的是 如果一个位置能到达，那么它左侧所有位置都能到达。
                    for(int j=k;j<=i+nums[i]&&j<n;j++)
                        able[j]=true;
                    k=i+nums[i];
                }
            }
            if(able[n-1]==true)
                return true;
        }
        return false;
    }
};


/*
看到一个比较好的想法（官方动态规划有点复杂）
思路一：
如果所有元素都不为0， 那么一定可以跳到最后；那么从后往前遍历，如果遇到nums[i] = 0，就找i前面的元素j，使得nums[j] > i - j。如果找不到，则不可能跳跃到num[i+1]，返回false。

思路二：贪心算法，每个位置都计算自己能达到的最远距离，同时每个位置要判断自己是否可达，也就是本位置需要在当前最远能到达的距离中。最终计算出来能到达的最远距离，与数组长度比较即可。
just try，超时间了，因为存储量过大，原版
bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> able(n,false); //每个元素自己是否可达，判断最后可达距离是否》n
        able[0]=true;
        for(int i=0;i<n;i++)
        {
            if(able[i]==true)
            {
                for(int j=1;j<=nums[i]&&i+j<n;j++) //注意一下i+j不能大于size
                able[i+j]=true;
            }
            if(able[n-1]==true)
                return true;
        }
        return false;
    }

神级别大佬提出的一个判定可不可以选取的条件语句：
大佬思路依据核心：如果一个位置能到达，那么它左侧所有位置都能到达。
bool canJump(vector<int>& nums) 
{
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false; //绝
		k = max(k, i + nums[i]);
	}
	return true;
}

作者：ikaruga
链接：https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/



*/
