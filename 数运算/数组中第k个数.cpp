215、数组中的第K个最大元素:未排序可重复序列找第k个元素。
思路：排序，但是时间大；改善思路：快排，第一个排序，左右分开，之后k比较要两边。（快速半排序）
官方思路2:建一个只能存K个数字的小顶堆，超过K时候，每加进来一个，堆顶就要弹出一个。数组遍历完，最终堆顶的元素就是第K大的。



/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n-k];
    }
};*/
/**利用快速排序中的partition思想解决，时间复杂度O(N); **/
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        srand(time(NULL));
        return findKthLargest(v, 0, v.size()-1, k);
    }
private:
    int findKthLargest(vector<int>& v, int l, int r, int k){

        int index = _partition(v, l, r);

        if( index+1 == k) return v[index];
        if( index+1 < k ) return findKthLargest(v, index+1, r, k );
        if( index+1 > k) return findKthLargest(v, l, index-1, k);

        return -1;
    }

    int _partition(vector<int>& v, int l, int r){

        int randIndex = rand()%(r-l+1)+l;
        swap(v[l], v[randIndex]);
        int e = v[l]; //放最前面

        int j = l, i = l+1;
        while(i <= r){
            if(v[i] >= e) swap(v[i], v[++j]);  //大的放前面，小的放后面不动
            i++;
        }
        swap(v[l], v[j]); //现在的vj 处放正确的值
        return j;
    }
};


/*
第k大，就是第n-k小的元素。之前二分中位数有做过，两个排序数组 去除两个k/2，不对没排序。
1、不限制时间，排序返回a【k】,太水了
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n-k];
2、建一个只能存K个数字的小顶堆，超过K时候，每加进来一个，堆顶就要弹出一个。数组遍历完，最终堆顶的元素就是第K大的（堆里其他元素都比他还要大）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};
3、快排，本来快排是两边都要递归，但是这里直接舍弃一边了，更快。第一个随机选择的数还是要排序左右
*/
