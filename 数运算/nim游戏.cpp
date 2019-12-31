//292、nim游戏：你先走，每次能拿走1-3个石头；拿到最后一个的人胜利，给n，你赢吗
//思路：每个人都是最优走法，如果输，拿4的人一定输，对方占据；4倍数一定输；

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)
        return false;
        else
        return true;
    }
};

/*
改成 按位运算，运行时间会更快-java
return ((n & 3) != 0);
*/
