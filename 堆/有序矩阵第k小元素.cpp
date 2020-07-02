378、有序矩阵中第k小的元素：每行/每列升序排列，返回第k小的元素（可能相同）
思路：最大堆，大于k个pop，尝试过了（必须要先push，再判定）；
官方：最优二分，对于数据k，《左上角/》右下角，个数统计（最后一行向上比较统计单列个数），再二分。

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;  //max 大根堆
        int m=matrix.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                q.push(matrix[i][j]);
                if(q.size()>k){
                    q.pop();
                }
            }
        }
        return q.top();
    }
};


/*
第k小先拿大根堆试试，过了

二分总感觉哪有bug，更快实现，最优
class Solution {
   public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

*/
