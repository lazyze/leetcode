class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //第k大元素
        quicksort(nums, 0, nums.size() - 1, k);
        return nums[nums.size() - k];
    }

    void quicksort(vector<int>& nums, int l, int r, int k) {
        if(l >= r) return ;
        int pivot = find(nums, l, r);
        //l ~ pivot pivot + 1 ~ r
        //第k个最大的元素位置为 size() - k
        if (pivot >= nums.size() - k) {
            quicksort(nums, l, pivot, k);
        } else {
            quicksort(nums, pivot + 1, r, k);
        }
    }

    int find(vector<int>& nums, int l, int r) {
        int mid = (l + r) >> 1;
        int tmp = nums[mid];
        while (l <= r) {
            while(nums[l] < tmp) l++;
            while(nums[r] > tmp) r--;
            if (l == r) break;
            if (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        return r;
    }
};