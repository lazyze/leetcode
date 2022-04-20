class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        //vector<int> pre(n + 1, 0);
        int tmp = 0;
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
            //pre[i] = min(pre[i - 1], sum[i]);
            ans = max(ans, sum[i] - tmp);
            //ans = max(ans, sum[i] - pre[i - 1]);
            tmp = min(tmp, sum[i]);
        }
        return ans;
    }
    //前缀和解法
    //连续子数组，前缀和相减
    //对于i，存在j < i,求sum[i] - sum[j]中的最大值 j可以为0
    //对于i，存在j < i,求sum[j]的最小值
    //用一数组记录，对于i， j < i中sum[j]的最小值
    //pre[j]表示在sum[0],sum[1],...sum[j]中的最小值
    //pre[j] = min(pre[j - 1], sum[j])
    // for (int i = 1; i < n; i++) ans = min(ans, sum[i] -  pre[i - 1]);
    //注意需要记录pre[0] = 0（连续子数组即为sum[i]本身，即sum[i] - sum[j]为 sum[i] - 0），
    //才能保证后续pre[j]正确

    //pre[]数组可简化为临时变量tmp
    //在循环中每次只需用到pre[i - 1],则数组可简化为临时变量在循环中一起更新
};