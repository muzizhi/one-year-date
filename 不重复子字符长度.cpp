//无重复字符的最长子串：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。“pwwkew”，无重复字符的最长子串是 “wke”，输出: 3。
//不太好想。暴力法检测o（n3）。优化减少重复检测。
//优化1:从i-j-1没有，那i-j只检测j重复就好了。对于i（全局遍历），j（i+1-n）找每个j是不是重复i-j-1。可以利用哈希表/滑动窗口形式表示o（2n）。
//最优化的思路：如果 s[j] 在[i,j) 范围内有重复的字符j‘，我们可以直接跳过[i，j’ ] 范围内的所有元素，并将i 变为 j‘+1。「长度不可能超过」o（n）。
//实验后发现：可以不用滑动窗口设定，然后最优化思路，双层循环 固定j，找不重复i是第几个，i=k+1；序列【i，j】长度解决。固定i，找j真的太难了。


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)
            return 0; //空字符
        int max=1;
        int i=0,j,k,temp;
        for(j=1;j<n;j++)  
        {
            //for(j=i+1;j<n;j++) //找s【j】是否【i，j）中有重复,两层循环一个break存储不来j,思考
            for(k=i;k<j;k++)  //思路：固定j，找不重复i是第几个，i=k+1；序列【i，j】
            {
                if(s[k]==s[j])
                {
                    i=k+1; //最优思路，省略前面的，不可能更长
                    break;
                }
            }  
            //cout<<j<<i<<endl;
            if(max<j-i+1)  //【1，2】bc 是两个字符
                max=j-i+1;
        }
        return max;                               
    }
};



/*
别人比较优秀的算法：
1、滑动窗口「不知道用没有，思想是」，思路应该是最优的那个。研究了
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)
                if(s[k]==s[j]){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};
评论：边界定义6，k遍历，i标定点，漏掉情况应该是没有的，因为从k到j是没有重复的

2、java代码，同样的思路利用滑动窗口形式表示o（2n）最多。
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }
}

*/

