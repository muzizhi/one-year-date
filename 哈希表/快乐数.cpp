//202、快乐数：如果一个数替换为各位数的平方和，循环下去如果最后等于1是快乐数
//思路：数的替换while循环一次，最后的循环判定flase的条件怎么提？无限循环不等于1，但是一个数出现了两次，就是false「hash！」
//或者用快慢 指针
//不快乐举例：4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 

class Solution {
public:
    bool isHappy(int n) {
        long res=0;
        unordered_map<long,int> hash;//存放图中的res，如果出现2次，途中没有1，flase
        while(res!=1)
        {
            while(n!=0)
            {
                res=(n%10)*(n%10)+res;
                n=n/10;
            }
            n=res;
            cout<<res<<endl;
            //hash[res]=1;   
            if(res==1)
                return true;
            if(hash.count(res)) //顺序反了，先判定之前出现过么，再进行输出
                return false;      
            hash[res]=1;  //res 存在为1    
            res=0; //错误循环，忘记了 每轮res归0 
        }
        return true;
    }
};


/*
//参考英文网站热评第一。这题可以用快慢指针的思想去做，有点类似于检测是否为环形链表那道题
//如果给定的数字最后会一直循环重复，那么快的指针（值）一定会追上慢的指针（值），也就是
//两者一定会相等。如果没有循环重复，那么最后快慢指针也会相等，且都等于1。
class Solution {
    public boolean isHappy(int n) {
        int fast=n;
        int slow=n;
        do{
            slow=squareSum(slow);
            fast=squareSum(fast);
            fast=squareSum(fast);
        }while(slow!=fast);
        if(fast==1)
            return true;
        else return false;
    }
    
    private int squareSum(int m){
        int squaresum=0;
        while(m!=0){
           squaresum+=(m%10)*(m%10);
            m/=10;
        }
        return squaresum;
    }
}
*/
