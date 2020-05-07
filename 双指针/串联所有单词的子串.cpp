30、串联所有单词的子串：给出s中所有words里单词串联的所有子串初始位置，words里单词统一长度，无返回空。
思路：所有单词包含顺序一遍为完成；map存string?For每个s固定长度，可以两个hash直接对比string。
优化：子串滑动考虑，char一个字符改动太多咋判定；不能char增入。
官方优化思路：多加一个长度word的for，每个i出个滑窗，之后固定递增单词word长度。那就是每个位置开始的可能都考虑全面了。Wrong：这里window要放进for更新。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.size()==0||words.size()==0) return res;
        unordered_map<string,int> need;
        for(string c : words) need[c]++;
        
        //多加的东西，word递增，确定长度
        int one_word=words[0].size();
        int word_num=words.size();
        int allword_long=one_word*word_num;

        for(int i=0;i<one_word;i++){ //多加的东西,确保所有可能char位 ，每个展开滑窗
            int l=i,r=i;
            int valid=0;
            unordered_map<string,int> window; //这里忘记更新了，wrong了一次
            //开启滑窗
            while(r+one_word<=s.size()){
                string c=s.substr(r,one_word);//从s中提取r后一个单词拷贝到c
                cout<<"c="<<c<<endl;
                r+=one_word;
                if(need.count(c)){
                    window[c]++;
                    if(need[c]==window[c]){
                        valid++;
                    }
                }
                cout<<"i="<<i<<"valid="<<valid<<endl;
                //回缩窗口 固定长度，找是否全部匹配
                while(r-l>=allword_long){
                    string d=s.substr(l,one_word);
                    if(valid==need.size()&&r-l==allword_long){
                        res.push_back(l);
                    }
                    if(need.count(d)){
                        if(need[d]==window[d]){
                            valid--;
                        }
                        window[d]--;
                    }
                    l+=one_word;
                    cout<<valid<<endl;
                }
            }
        }
        return res;
    }
};

/*
次数也有限制，必须全部一遍完 才有输出，否则输出为空
那个框架没有，n/win不好设定，都是sting，但是char一个字符改动太多咋判定；不能char增入。
官方优化思路：多加一个长度word的for，每个i出个滑窗，之后固定递增单词word长度。那就是每个位置开始的可能都考虑全面了。

wrong,懂了，因为for循环了，但是window没有更新恢复为0； 

*/
