class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //单调队列维护窗口 ，队头为时间最早的最大值
        deque<int> rec;
        vector<int> rt;
        for (int i= 0; i < nums.size(); i++) {
            while(!rec.empty() && i - rec.front() >= k) {
                rec.pop_front();
            }
            while(!rec.empty() && nums[i] >= nums[rec.back()]) {
                rec.pop_back();
            }
            rec.push_back(i);
            if (i + 1 >= k) {
                rt.push_back(nums[rec.front()]);
            }
        }
        return rt;
    }
};