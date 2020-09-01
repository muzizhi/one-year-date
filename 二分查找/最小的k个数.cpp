29、最小的k个数：无序数组的输出，练习排序。k个数可以无序输出
思路：尝试一下快排实现，过界1h。快排j指小后，i指遍历。先小的i++/j++都走完，之后，大了只i++，小的交换/j++/i++。Ok 
更容易接受的思路：i前，j后，i++/j--，然后不对交换。以及大根堆实现，存k个之后开始比较，大的拿走小的留下。最后输出k个值。




class Solution {
public:
//vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> getLeastNumbers(vector<int>& input, int k) {
        int n=input.size();
        vector<int> res;
        if(n==0|| k==0) return res;
        return quicksort(input,k-1,0,n-1);
    }

    vector<int> quicksort(vector<int> &arr,int k,int l,int r){
        int j=partition(arr,l,r);
        //cout<<j<<endl;
        if(j==k){  //如果找到了快排的位置，返回其左边k个
            vector<int> res;
            for(int i=0;i<=k;i++){ //输出不对，从j往前推k个。l不一定是最左边
                res.push_back(arr[i]);
            }
            return res;
        }
        if(j<k) return quicksort(arr,k,j+1,r);
        else return quicksort(arr,k,l,j);
    }

    int partition(vector<int> &arr,int l,int r){
        int p=arr[l];
        int i=l+1,j=l+1; // i直接走，j指向小的末尾下一个，随后方便交换
        while(i<=r && arr[i]<arr[l]){  //注意i《r，越界
                i++; j++;
            }
        while(i<=r){ //前面的已经搞完，后来大的不动，小的提前
            if(arr[i]<arr[l]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++; j++;
            }
            else{
                i++;
            }
        }
        arr[l]=arr[j-1];
        arr[j-1]=p;
        //for(int i=l;i<=r;i++){
        //    cout<<arr[i];
        //}
        return j-1;
    }
    
};

/*
快排尝试，k 比较排序的j，然后继续分左/右，简化计算， 知道找出下标为k-1 的对应数，返回其左


别人的思路，比较好理解，第一个保留，i左右，j右边，小的i++，大的j--，不对劲，i/j换一下 中间搞定。
大根堆思路，c++实现
vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) return vec; // 排除 0 的情况
        priority_queue<int>Q;
        for (int i = 0; i < k; ++i) Q.push(arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }

*/
