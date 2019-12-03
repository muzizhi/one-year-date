//有效数独判定：当前 9x9 数独满足以下规则有效：数字 1-9 在每一行/列只能出现一次；1-9 在每一个粗实线分隔的 3x3 小格子内只能出现一次；
//空白用。表示。无和要求
//思路：可以利用哈希表。总共遍历3/1次，看每个点是否符合。实际写的时候用的数组，然后设定行【i】【值】=次数，
//不会哈希表的撤销。对于每行/列/单元都要新建，有时间重写。
//官方思路：遍历一次，建立了3个9*9的哈希表不需要撤销。还有人利用位操作

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //unordered_map<int,int> hash;//不会哈希表的撤销
        vector<vector<int>> rows(9,vector<int>(10,0)); //设定为 9行，每行值 可以写0-9，10个数
        vector<vector<int>> cols(9,vector<int>(10,0)); 
        vector<vector<int>> block(9,vector<int>(10,0)); 
        int m=board.size();
        int n=board[0].size();
        int t;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                //if(board[i][j]==".") wrong,can't 
                if(board[i][j]=='.')
                    continue;
                else t=board[i][j]-'0';
                if(rows[i][t]==0)
                    rows[i][t]=1;//行 已经被访问
                else return false;
                if(cols[j][t]==0)
                    cols[j][t]=1;//列 已经被访问
                else return false;
                //int block_num=(i|3)*3+(j|3); //定义块号
                cout<<1/3<<1%3; //报错没有|这个操作符
                int block_num=(i/3)*3+(j/3);
                if(block[block_num][t]==0)
                    block[block_num][t]=1;
                else return false;    
            }
        return true;
    }
};


/*
哈希表建立三个，可以一次迭代解决：
感觉像是数组啊，没有利用哈希表的count
思路是：行【i】【数】=0，第一次出现改为1，不是第一次出现，false。
class Solution { //java官网
  public boolean isValidSudoku(char[][] board) {
    // init data
    HashMap<Integer, Integer> [] rows = new HashMap[9];
    HashMap<Integer, Integer> [] columns = new HashMap[9];
    HashMap<Integer, Integer> [] boxes = new HashMap[9];
    for (int i = 0; i < 9; i++) {
      rows[i] = new HashMap<Integer, Integer>();
      columns[i] = new HashMap<Integer, Integer>();
      boxes[i] = new HashMap<Integer, Integer>();
    }  

    // validate a board
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char num = board[i][j];
        if (num != '.') {
          int n = (int)num;
          int box_index = (i / 3 ) * 3 + j / 3;

          // keep the current cell value
          rows[i].put(n, rows[i].getOrDefault(n, 0) + 1);
          columns[j].put(n, columns[j].getOrDefault(n, 0) + 1);
          boxes[box_index].put(n, boxes[box_index].getOrDefault(n, 0) + 1);

          // check if this value has been already seen before
          if (rows[i].get(n) > 1 || columns[j].get(n) > 1 || boxes[box_index].get(n) > 1)
            return false;
        }
      }
    }

    return true;
  }
}

也有人利用位运算进行相等判定的。//三次 遍历实现的也有 //或者用数组实现的也有
*/
