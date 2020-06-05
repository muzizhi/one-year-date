60、第k个排序：给出n，代表1-n数字全排列，返回从小到大的第k个数（返回string
思路：全排列，然后返回第k个大小，超时；全排列直接第k个结束，输出错误奇怪。
最优：数学推理每位数字：k-1开始，由i = k/(n-1/2/..)！得出对应位置的索引，并由k = k%(n - 1/2)！更新k，然后删除nums数组已有元素。



class Solution {
public:
int factorial(int n) {   //计算n！
  int num = 1;
  while (n > 0)
    num *= n--;
  return num;
}
void deleteItem(int *nums, int numsSize, int in) {  //删除num数组
  while (in < numsSize - 1)
    nums[in++] = nums[in + 1];
}
char *getPermutation(int n, int k) {   //获取对应值
  int i, j = 0, nums[n], factor;
  char *res = (char *)calloc(10, sizeof(char));
  for (i = 0; i < n; i++)  //初始化一个 [1,2,3,……,n] 数组
    nums[i] = i + 1;
  for (i = 0, k--; i < n; i++) {  //k要先减去1
    factor = factorial(n - i - 1);
    res[j++] = nums[k / factor] + '0';
    deleteItem(nums, n - i, k / factor);  //取出一个元素
    k %= factor;
  }
  return res;
}
};

/*
给出n的全排列，然后返回第k个大小？ 最容易的思路，全排列实现了，但是超时
//全排列输出所有数组尝试一下
    vector<int> res;
    vector<vector<int>> results;

    vector<vector<int>> allnums(int n, vector<int> flag) {
        if(res.size()==n){  //123
            for(int j=0;j<n;j++){
                cout<<res[j];
            }
            cout<<endl;
            results.push_back(res);
        }
        for(int i=0;i<n;i++){
            if(flag[i]==0){ //未访问
                flag[i]=1;
                res.push_back(i+1); //1234--0123
                allnums(n,flag);
                flag[i]=0;  //回溯
                res.pop_back(); 
                
            }
        }
        return results;
    }

优化：全排列直接第k个结束，排列本来就有顺序; 我自己调整了半天总是输出不了res； 然后就没办法

数学思路：ifn=4.k=15： 1开头 （3！=6）个； so3开始的第三个 ；k当作14
第一位 index = k / (n-1)! = 2, 说明第15个数的第一位是3，？？？不是很懂3？num【index】
更新k： k = k % (n-1)! = 14-2*6= 2  循环更新

更简洁的思路，故n=6 k = 373 时，全排列的第一个数字应该是 nums[ k / 5! ] = 4 ;
数组删除 4, 此时 nums = [1, 2, 3, 5, 6]; k % 5! = 12 ;
接下来就是在 nums 中找第 12 个全排列，重复 1，2 步即可 。
注意数组下标是从 0 开始，k 首先要减去 1

*/
