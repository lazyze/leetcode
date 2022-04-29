class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergesort(nums, 0, nums.size() - 1);
        return ans;
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if(l >= r) return ;
        int mid = (l + r) >> 1;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        calculate(nums, l, mid, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        vector<int> tmp(r - l + 1);
        for (int k = 0; k < tmp.size(); k++) {
            if (j > r || (i <= mid && nums[i] <= nums[j])) {
                tmp[k] = nums[i++];
            } else tmp[k] = nums[j++];
        }
        for (int k = 0; k < tmp.size(); k++) {
            nums[l + k] = tmp[k];
        }
    }

    void calculate(vector<int>& nums, int l, int mid, int r) {
       for (int i = l, j = mid + 1; i <= mid; i++) {
           while(j <= r && nums[i] > 2l * nums[j]) j++;
           ans += j - 1 - (mid + 1) + 1;
       }
    }

    int ans;
};