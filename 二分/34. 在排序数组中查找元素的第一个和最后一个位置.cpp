class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //第一个大于等于target的值
        //最后一个小于等于target的值
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int rtl = r;
        l = -1;
        r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] <= target){
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int rtr = l;
        if(rtl > rtr) return {-1, -1};
        return {rtl, rtr};
    }
};