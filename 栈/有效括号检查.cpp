//20、有效的括号：要求要对应，并且顺序注意。“{[]}”true；”([)]”false
//思路：对应括号必须相差奇数位，一万个问题。换成右括号前面必须有正确个数左括号也不对，可能顺序有误。
//官方：利用栈的存储思路。开括号进栈，闭括号pop匹配。匹配可以另外建立compare函数，也可以利用哈希表匹配

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();  //string 类型的总数也是这么求解
        if(n%2!=0)  return false;
        stack<char> m_stack; //栈的定义，终于懂得说数据结构 是什么意思了

        for(int i=0;i<n;i++)  //左括号入栈， 右括号出栈匹配，失败false
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') 
            m_stack.push(s[i]);
            else if(s[i]==')'||s[i]==']'||s[i]=='}')
            {
                if(m_stack.empty()) //这个必须单独说明，放在compare里面容易编译错误
                return false;
                else if(compare(m_stack.top(),s[i]))
                m_stack.pop();
                else return false;//应该是 compare失败。
            }
        }
        if(m_stack.empty())
        return true; //"{{)}"
        else return false;
    } 
    bool compare(char &a,char &b)
    {
        //return (c1 == '[' && c2 == ']') || (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}');
        if(a=='('&&b==')'||a=='['&&b==']'||a=='{'&&b=='}')
            return true;
        else return false;

    }  
};

/*理解错误，以为只有顺序比较，没有"{[]}"，重新构思。
然后按照相差基数，以及统计左右括号考虑，都有情况不一样。
"{{)}"   "){"   "{[]}"
看了官方思路，考虑采用数据结构--栈，更好解决。
编译报错的一版本，不懂为啥
stack<char> m_stack; //栈的定义，终于懂得说数据结构 是什么意思了

        for(int i=0;i<n;i++)  //左括号入栈， 右括号出栈匹配，失败false
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') 
            m_stack.push(s[i]);
            else if(compare(m_stack.top(),s[i])) //compare 正好是true，false
            m_stack.pop();
            else
            return false;//应该是 compare失败，或者是没有匹配到。
        }
        if(m_stack.empty())
        return true; //"{{)}"
        else return false;
        
在匹配的时候，用哈希表同步表示：
bool isValid(string s) {
        if(s.length()%2!=0) return false;//一但是奇数说明不是有效的括号
        map<char,char> wordbook;//建立哈希表
        wordbook.insert(map<char,char>::value_type(')','('));
        wordbook.insert(map<char,char>::value_type(']','['));
        wordbook.insert(map<char,char>::value_type('}','{'));
        stack<char> mystack;//建立栈
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')//匹配到左括号
                mystack.push(s[i]);//放入栈中
            else if(s[i]==']'||s[i]=='}'||s[i]==')')//匹配到右括号
            {
                if(mystack.empty()) return false;
                //匹配到右括号，栈中应该存在左括号。否则就是无效的括号
                if(wordbook[s[i]]==mystack.top())//与栈顶元素进行匹配
                {
                    mystack.pop();//匹配成功删除栈顶元素
                    continue;
                }
                else return false;
            }
        }
        if(mystack.empty()) return true;//有效的括号到最后检测结束栈中应没有元素
        else return false;
    }

作者：chenlele
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-gpe3dbjds1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
