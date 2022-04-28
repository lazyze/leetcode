class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int r = 0;
        for (auto& it : nums) {
            l = max(l, it);
            r += it;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if(isok(mid, nums, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
    bool isok(int v, vector<int>& nums, int m) {
        int sum = 0;
        int n = 1;
        for (auto& it : nums) {
            sum += it;
            if(sum > v) {
                sum = it;
                n++;
            }
        }
        return n <= m;
    }
};