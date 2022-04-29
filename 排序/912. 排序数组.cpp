// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         //快排
//         quicksort(nums, 0, nums.size() - 1);
//         return nums;
//     }

//     void quicksort(vector<int>& nums, int l, int r) {
//         if(l >= r) return ;
//         int midPos = find(nums, l, r);
//         quicksort(nums, l, midPos);
//         quicksort(nums, midPos + 1, r);
//         return ;
//     }

//     int find(vector<int>& nums, int l, int r) {
//         int v = nums[(l + r) >> 1];
//         while (l <= r) {
//             while(nums[l] < v) l++;
//             while(nums[r] > v) r--;
//             if(l == r) break;
//             if(l < r) {
//                 swap(nums[l], nums[r]);
//                 l++;
//                 r--;
//             }
//         }
//         return r;
//     }
// };

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    //归并排序
    void mergesort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int mid = (l + r) >> 1;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l1, int r1, int r2) {
        vector<int> tmp(r2 - l1 + 1);
        int k = 0;
        int l = l1;
        int l2 = r1 + 1;
        while(l1 <= r1 && l2 <= r2) {
            if(nums[l1] <= nums[l2]) tmp[k++] = nums[l1++];
            else tmp[k++] = nums[l2++];
        }
        while (l1 <= r1) {
            tmp[k++] = nums[l1++];
        }
        while (l2 <= r2) {
            tmp[k++] = nums[l2++];
        }
        for (auto& it : tmp) {
            nums[l++] = it;
        }
    }
};