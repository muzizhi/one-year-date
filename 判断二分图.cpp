785、判断二分图：图点分a和b，if每边都是a-b叫二分图，邻接表graph[i]与i相连
思路：无自环。邻接表存了n个集合，一个集合里面的肯定一类，如何判定相同/不同类
官方思路：染色法，一个节点开始绿色，相连红色，红色相连绿色again，如果已被染色wrong。深度或者广度遍历无色的，但是都必须多次，不一定连通。




class Solution {
public:
    //尝试广度遍历，迭代
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0); //0 无色， 1red ，2 green
        //bool valid=true;
        for(int i=0;i<n;i++){//  i个节点无色多次遍历
            if(color[i]==0){
                color[i]=1;
                //怎么表示遍历结束了,用栈节点存储,顺序不对，用队列
                queue<int> q;
                q.push(i);
                while(!q.empty()){  //怎么表示遍历结束了
                    int node=q.front();
                    q.pop();
                    int trans= color[node]==1? 2:1;
                    for(auto neigh:graph[node]){
                        if(color[neigh]==0){
                            q.push(neigh);                    
                            color[neigh]=trans;
                        }
                        else if(color[neigh]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

       

/*
相连就不是一个集合，然后划分，然后验证；直接集合内是1个集合，验证
123  02  重复不可能


官方dfs，染色法递归，简单讲就是：她红，邻居if无色，dfs绿色，有色wrong。 存储颜色数组，图多次遍历
class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;
    bool valid;

public:
    void dfs(int node, int c, const vector<vector<int>>& graph) {
        color[node] = c;
        int cNei = (c == RED ? GREEN : RED);
        for (int neighbor: graph[node]) {
            if (color[neighbor] == UNCOLORED) {
                dfs(neighbor, cNei, graph);
                if (!valid) {
                    return;
                }
            }
            else if (color[neighbor] != cNei) {
                valid = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        valid = true;
        color.assign(n, UNCOLORED);
        for (int i = 0; i < n && valid; ++i) {
            if (color[i] == UNCOLORED) {
                dfs(i, RED, graph);
            }
        }
        return valid;
    }
};


*/
