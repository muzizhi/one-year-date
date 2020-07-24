65、矩阵中的路径：矩阵存字符（可重复），然后判断是否有路径对应字符串。
思路：上下在范围内，走过flag=1，dfs，如果找不到报错。不回溯尝试错/多个e回溯。容易错的地方：对于每个点开始都要dfs/可能多条。牛客过了char，leetcode超时。
优化：不需要flag，就用矩阵元素，temp保存，mat=“#”，然后回归//先用边框确认范围，然后在后续判断dfs。


class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==nullptr || str==nullptr) return false;
        vector<int> flag(rows*cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(matrix,str,0,rows,cols,i,j,flag)){
                    return true;
                }
            }
        }
        cout<<strlen(str); //abc =3
        return false;
    }
    
     bool dfs(char* matrix,char *str,int depth,int rows,int cols,int x,int y,vector<int> flag){
        if(str[depth]!=matrix[x*cols+y]) return false;
        if(depth+1==strlen(str)){  //不能放前面，如果只有1位
            return true;
        }
        //else{
            flag[x*cols+y]=1;
            bool a=false,b=false,c=false,d=false;
            if(x-1>=0 &&flag[(x-1)*cols+y]==0){
                a=dfs(matrix,str,depth+1,rows,cols,x-1,y,flag);
            }
            if(x+1<rows &&flag[(x+1)*cols+y]==0){
                b=dfs(matrix,str,depth+1,rows,cols,x+1,y,flag);
            }
            if(y-1>=0 &&flag[x*cols+y-1]==0){
                c=dfs(matrix,str,depth+1,rows,cols,x,y-1,flag);
            }
            if(y+1<cols &&flag[x*cols+y+1]==0){
                d=dfs(matrix,str,depth+1,rows,cols,x,y+1,flag);
            }
            flag[x*cols+y]=0;
            return a||b||c||d;
        //}
        return false;
    }


};


//判断是否有字符串路径： 上下在范围内，走过flag=1，如果找不到报错。假设不回溯尝试
//还是要回溯, 并且每个点作为开始判定。很麻烦，很难写,why wrong
