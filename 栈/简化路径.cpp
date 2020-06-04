71、简化路径：转换成规范路径（/开头|/不结尾|///=/|化简。/。父。/。当前/）
思路：开头结尾好去，化简重点：。退/ ；。。退/ /间内容；麻烦还是要辅助一下，只保留//之间的内容，数组或者栈，最后按规范输出。


class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        int i=0;
        string res="";
        vector<string> stack;
        while(i<n){
            //while(path[i]=="/"){  //wrong i<n
            while(i<n&& path[i]=='/'){
                i++;  
            }
            while(i<n&& path[i]!='/'){  //中间/ /保留着为res
                res+=path[i];
                i++;
            }
            if(res==".."){  //。。退
                if(!stack.empty()){
                    stack.pop_back();
                }
            }
            else if(!res.empty() &&res!="." && res!=".."){
                stack.push_back(res);
            }
            res=""; //重新 为空      
        }
        if(stack.empty()){
            return "/";
        }
        res="";
        for(int j=0;j<stack.size();j++){ //最后输出
            res+="/";
            res+=stack[j];
        }
        return res;
    }
};


/*
开头结尾好去，化简重点（。不管|。。前移） 双点和 单点都是 后退一个， 。退/ ；。。退/ 和到前一个/的字母
还是要辅助一下，只保留//之间的内容，最后按规范输出

wrong ,if char==' '; if string ==" ";

利用栈辅助： 比较好理解
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream iss(path);
        string buf;
        while (getline(iss, buf, '/')) {  //按照/分开，字母加入v，。。后退
        
};
*/
