//406、根据身高重建序列：每个人（h\k）h代表身高，k队列前高于他的人数，打乱了顺序，按h、k要求重建队伍。
//思路：按照h和k先排序，最小的h要在k位置上（第k+1个数）。然后去掉这个换第二小的同样填空，越过已经排序好的数继续找空格填空（本身也算空格）。
//另一个思路：按h从大向小，k小到大排序，每个插入都是固定位置，改变后续位置。

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
       // vector<vector<int>> rec(n,vector<int>(2)); //n行2列，初始化赋值怎么弄
        vector<vector<int>> rec(n,vector<int>{-1,-1}); //-1更稳妥
        sort(people.begin(),people.end()); //直接按照h小-大，k小到大
        for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
        {
            cout<<people[i][j];
        }

        for(int i=0;i<n;i++)
        {//直接找第k+1个空格坐下
            int count=-1;
            int j=0; // j是新数组rec 的指针
            while(count<people[i][1])  //people=0
            {
                if(rec[j][0]==-1||rec[j][0]==people[i][0])//空位置，还没有放值,跟自身值一样也算空格
                {
                    count++;
                }
                j++;
            }
            cout<<j-1<<endl;
            rec[j-1][0]=people[i][0];
            rec[j-1][1]=people[i][1];
        }
        return rec;

    }
};

/*
自我思路：从小到大排，每一个小的位置是空格插空相应k空位

思路2:按照从大到小排列，书读的少啊，以为这样每次都要动，是不是需要链表很麻烦233
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先排序
        // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
        
        // 再一个一个插入。
        // [7,0]
        // [7,0], [7,1]
        // [7,0], [6,1], [7,1]
        // [5,0], [7,0], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] > b[0]) return true;
            if (a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });
        
        vector<vector<int>> res;
        for (auto& e : people) {
            res.insert(res.begin() + e[1], e);
        }
        return res;
    }
};

作者：ivan_allen
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-pai-xu-hou-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
