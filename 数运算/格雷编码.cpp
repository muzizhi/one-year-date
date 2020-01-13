//89、格雷编码：给定总位数n，格雷码连续值之间只能相差一位，输出一种格雷码序列。
//思路：最开始思考递归，010 和110怎么链接？n=2前面加0输出，前面加1反向输出。从而能够每个值只差一位。
//大佬思路：找规律题目，关键是搞清楚格雷编码的生成过程, G(i) = i 异或i右移一位/i^ i/2。如：G(3) = 3 ^ 1 = 011 ^ 001 = 010「异或」

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        if(n==0)return {0};
        else
        {
            gray=grayCode(n-1);//顺序输出
            vector<int> temp=gray;
            //temp.reverse(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());//逆序
            for(int i=0;i<temp.size();i++)
            {
                gray.push_back(temp[i]+pow(2,n-1));//逆序首位加1 输出
                cout<<temp[i]+pow(2,n-1);
            }
        }
        return gray;
    }
};

/*
这居然还是一个找规律题目
关键是搞清楚格雷编码的生成过程, G(i) = i ^ (i/2); 异或操作神奇了
        如 n = 3: 
        G(0) = 000, 
        G(1) = 1 ^ 0 = 001 ^ 000 = 001
        G(2) = 2 ^ 1 = 010 ^ 001 = 011 
        G(3) = 3 ^ 1 = 011 ^ 001 = 010
        G(4) = 4 ^ 2 = 100 ^ 010 = 110
        G(5) = 5 ^ 2 = 101 ^ 010 = 111
        G(6) = 6 ^ 3 = 110 ^ 011 = 101
        G(7) = 7 ^ 3 = 111 ^ 011 = 100
        List<Integer> ret = new ArrayList<>();
        for(int i = 0; i < 1<<n; ++i)
            ret.add(i ^ i>>1);
        return ret;

利用格雷码的性质，一个简单的递归就可以解决了，已知n-1的格雷码集合，在前面加一个0，然后把n-1的集合前面加一个1 集合反向输出，就得到n的格雷码集合了
*/
