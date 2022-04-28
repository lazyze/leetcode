//二叉堆解法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pqueue;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            pqueue.push(make_pair(nums[i], i));
            if (i < k - 1) {
                continue;
            }
            auto it = pqueue.top();
            while (it.second < i - k + 1) {
                cout << "t" << it.second << endl;
                pqueue.pop();
                it = pqueue.top();
            }
            ans.push_back(it.first);
        }
        return ans;
    }
};