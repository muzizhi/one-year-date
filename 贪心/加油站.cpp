//134、加油站：环路n个加油站，油箱开始为空无限容量，路上花费cost[i]，油站可加g[i]，若从i可走一周，输出i，否则输出-1；
//思路：贪心，从i=0考虑，能加的油都加，看能不能走到最后。都不行-1

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g,j;//油箱目前含油量 定义int gas 命名冲突
        int i=0;
        int n=gas.size();
        while(i<n) //i从0开始看看 哪个能走一圈
        {
            g=0;j=0;
            while(j<n)// j代表走过几个加油站，i=0,i+j/n 取值 从自身，j++到最后一个停
            {
                g+=gas[(i+j)%n];
                //cout<<g<<endl;
                if(g-cost[(i+j)%n]>=0)
                {
                    g=g-cost[(i+j)%n];
                    //cout<<g<<" "<<j<<endl;
                    j++;
                }
                else
                    break;
            }
            if(j==n) //走完了所有加油站
                return i;
            else
            i++;
        }
        //if(i==n)
        return -1;
    }
};
