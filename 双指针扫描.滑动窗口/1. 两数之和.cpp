class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> rec;
        for (int i = 0; i < nums.size(); i++) {
            rec.push_back(make_pair(nums[i], i));
        }
        sort(rec.begin(), rec.end());
        int begin = 0;
        int end = nums.size() - 1;
        while(begin < end) {
            if (rec[begin].first + rec[end].first > target) {
                end--;
            } else if (rec[begin].first + rec[end].first < target) {
                begin++;
            } else return {rec[begin].second, rec[end].second};
            
        }
        return {};
    }
};