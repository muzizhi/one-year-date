//45、跳跃游戏2:数组位置表最大跳跃步数，输出从1到n最少跳跃步数
//思路：贪心直接要最大步数，感觉不对。感觉还是挨个跳。计算步数和最远可到距离。当前在i，步数+1，最远可到k（则i+1-k之间都是c步）。当k超过终点，输出步数，搞定；
// 不用两个循环，不用记录i不输出路径。直接c步最远k，走到k之前最远k’。k-k’就是c。
//思路二：倒退，直到能到0位置。遍历一边，从【i，n-1】最小的一步能到n的。下一次就是【i，n‘-1】，更新n到0位置。

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0;//步数统计
        int k=0,i=0,t;//i当前位置，最远能到k，则i-k之间都是c步；
        if(n==2)
            return 1;

        while(k<n-1)   //注意是n-1，k是下标
        {
            int temp=k;
            for(int j=i;j<=temp;j++)
            {
                //  错误用例【1，2，3】解决，j<=temp,k=0开始
                if(k<=j+nums[j])
                {
                    k=j+nums[j];
                    t=j;
                }
            }
            cout<<k<<endl;
            i= t+1;//保存能走到最远的那个坐标 下标,下一次从搜索范围【i+1,k】
            count++;
            cout<<i<<count<<endl;
        }
        return count;
    }
};

/*
难度为难的问题，果然很难想啊，延续上一个挨个跳思路尝试，成功啦啦啦啦

思路：贪心
思路一：跟我的思路差不多一样，但是时间复杂度，降低到1个for上面；
我的思路，记录了每步的位置i其实。然后考虑的是i最远到k，下一次考虑i-k之间是c步。「双层是有重复」

思路：第一步最远k，第二步最远k‘，那么k-k'之间都是2步到达。

Java
public int jump(int[] nums) {
    int end = 0;
    int maxPosition = 0; 
    int steps = 0;
    for(int i = 0; i < nums.length - 1; i++){
        //找能跳的最远的
        maxPosition = Math.max(maxPosition, nums[i] + i); 
        if( i == end){ //遇到边界，就更新边界，并且步数加一
            end = maxPosition;
            steps++;
        }
    }
    return steps;
}


思路二：
我们知道最终要到达最后一个位置，然后我们找前一个位置，遍历数组，找到能到达它的位置，离它最远的就是要找的位置。然后继续找上上个位置，最后到了第 0 个位置就结束了。
至于离它最远的位置，其实我们从左到右遍历数组，第一个满足的位置就是我们要找的。

Java
public int jump(int[] nums) {
    int position = nums.length - 1; //要找的位置
    int steps = 0;
    while (position != 0) { //是否到了第 0 个位置
        for (int i = 0; i < position; i++) {
            if (nums[i] >= position - i) {
                position = i; //更新要找的位置
                steps++;
                break;
            }
        }
    }
    return steps;
}
时间复杂度：O(n²)，因为最坏的情况比如 111111
空间复杂度：O(1)。

作者：windliang
链接：https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/

*/
