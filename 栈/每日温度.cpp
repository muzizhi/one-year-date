739、每日温度：给出温度列表，返回离温度up天间距，无则0，返回新列表。
思路：暴力，for（for有大）；用哈希存储索引的话，能搜索比谁大吗？貌似不行
官方思路：单调栈，栈1放索引，vector放结果。栈1，如果有元素j比栈顶i大，移除栈顶，ans[i]=j-i；栈顶小入栈。最后结束在栈里的都为0



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        int n=T.size();
        vector<int> res(n,0);
        //单调栈t小 index入栈  大的替换出res
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
            }
            //大的替换出res
            while(!s.empty() &&T[i]>T[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};


/*
从整体来说，存哈希表，哈希（结果）=索引，然后搜索是否比他大，返回第一个元素 .能搜索比他大吗?? maosi no

官方思路：单调栈
*/

/**
 * 根据题意，从最后一天推到第一天，这样会简单很多。因为最后一天显然不会再有升高的可能，结果直接为0。
 * 再看倒数第二天的温度，如果比倒数第一天低，那么答案显然为1，如果比倒数第一天高，又因为倒数第一天
 * 对应的结果为0，即表示之后不会再升高，所以倒数第二天的结果也应该为0。
 * 自此我们容易观察出规律，要求出第i天对应的结果，只需要知道第i+1天对应的结果就可以：
 * - 若T[i] < T[i+1]，那么res[i]=1；
 * - 若T[i] > T[i+1]
 *   - res[i+1]=0，那么res[i]=0;
 *   - res[i+1]!=0，那就比较T[i]和T[i+1+res[i+1]]（即将第i天的温度与比第i+1天大的那天的温度进行比较）
 public int[] dailyTemperatures(int[] T) {
    int[] res = new int[T.length];
    res[T.length - 1] = 0;
    for (int i = T.length - 2; i >= 0; i--) {
        for (int j = i + 1; j < T.length; j += res[j]) {
            if (T[i] < T[j]) {
                res[i] = j - i;
                break;
            } else if (res[j] == 0) {
                res[i] = 0;
                break;
            }
        }
    }
    return res;
}
 */



