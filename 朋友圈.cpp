//547、朋友圈：误会为岛屿，mij=1，ij是朋友，相互连通为朋友圈；几个？位置无关
//思路：不是岛屿，直接连通没用；对角对称看一半，每行建立一个pyq，判断连通，感觉在画图？不会考虑dfs咋弄？
//官方思路：实际上dfs图结构，具体有点像行懂了ifm=1，没访问过，访问并继续dfs；全局访问过有几个dfs// 了解并查集思想

class Solution {
public:
    void getdfs(vector<vector<int>>& M,int a,vector<int> &visit){// 注意&
        //对于i找相连接的，dfs到底，改为 访问区域
        int n=M.size();
        visit[a]=1; //visited
        for(int j=0;j<n;j++){
            if(M[a][j]==1&& visit[j]==0){ //去找相邻未访问区域
                visit[j]=1;
                cout<<j<<visit[j]<<endl;
                getdfs(M,j,visit);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& M) {
        int m=M.size();
        if(m==0) return 0;
        vector<int> visit(m,0); // start with no visited
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(visit[i]==0){
                getdfs(M,i,visit);
                count++;
            }
        }
        return count;
    }
};

/*
我服了，不是岛屿理解错了， 连通是ij连通，只看一半的话，怎么连通各地呢，图结构我不是很熟悉
看了解析有点懂了，虽然说是图思路，但是还是数组实现
对于n个数，都没有访问，按行dfs 1与3相连，继续dfs3；  访问过的标记
看看总共要标记几回
并查集讲解：
https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/
*/
