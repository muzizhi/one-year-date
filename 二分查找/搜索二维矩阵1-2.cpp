74、搜索二维矩阵：高效查找m*n矩阵是否存在t，矩阵行升序，且n行首列>n-1行尾巴
思路：连接有序，完全就是二分，转化成一维数组方便。成功；官方：设立idex（0-m*n-1），二分对应值是 row = idx / n ， col = idx % n。（n为列）


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        //一维数组
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(matrix[i][j]);
            }
        }
        int l=0, r=temp.size()-1;
        while(l<=r){  //wrong in 只有一个元素 <=
            int mid=(l+r)/2;
            if(temp[mid]==target){
                return true;
            }
            if(temp[mid]<target){
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return false;
    }
};

/*
完全就是二分，转化成一维数组方便

更优，虚拟转化
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];

*/

240、搜索二维矩阵2: 高效查找m*n矩阵是否存在t，矩阵行列升序排序
思路：每列思考，如果 t《头或者 t》尾，不在； 否则二分找值，莫名超时烦人。明明可
更优快速思路：只看左下角，如果=对，如果〉说明不可能这行，去掉；如果〈说明不可能这列去掉。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        int i = matrix.size()-1;
        int j=0,n=matrix[0].size();
        while(i>=0 && j < n) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target) {  //左下角小，说明这列没有
                j++;  
            }
            else {
                i--;
            }
        }
        return false;
    }
};


/*
思路：每列思考，如果 t《头或者 t》尾，不在； 否则二分找值, 超时间-但是我自己运行时没有报错的，好烦人
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        //cout<<m<<n<<endl;
        for(int j=0;j<n;j++){
            if(matrix[0][j]<=target && matrix[m-1][j]>=target){   //wrong 忽略=，如果等也是true
                //cout<<j<<endl;
                if(seek(matrix,j,m,target)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool seek(vector<vector<int>> matrix,int j,int m,int target){
        int l=0,r=m-1;
        while(l<r){
            int mid=(l+r)/2;
            if(matrix[mid][j]==target){
                return true;
            }
            if(matrix[mid][j]<target){
                l=mid+1;
            }
            else
                r=mid-1;
            //cout<<j<<mid<<l<<r<<endl;
        }
        if(matrix[l][j]==target)  return true;  //可能l=r，然后没有比较出来了
        return false;
    }

他们的思路确实实现起来更快速， 只看左下角，如果=对，如果〉说明不可能这行，去掉；如果〈说明不可能这列去掉。
*/







