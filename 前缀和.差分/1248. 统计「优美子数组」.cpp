class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int num = nums.size() + 1;
        vector<int> presum(num, 0);
        for (int i = 1; i < num; i++) {
            presum[i] = presum[i - 1] + nums[i - 1] % 2;
        }
        vector<int> count(num, 0);
        int ret = 0;
        count[0] = 1;
        for (int i = 1; i < num; i++) {
            count[presum[i]]++;
        }
        for (int i = 0; i < num; i++) {
            if(presum[i] - k >= 0)
                ret += count[presum[i] - k];
        }
        return ret;
    }
    //前缀和数组prenum[]
    //对于i，有多少j(0 ~ i-1)，使得prenum[i] - prenum[j] = k;
    //prenum[i] - k = prenum[j];
};