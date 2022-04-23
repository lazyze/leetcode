class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        flag = vector<bool> (n, false);
        this->nums = nums;
        recursive(0);
        return ans;
    }

    void recursive(int pos) {
        if (pos == n) {
            ans.push_back(v);
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (flag[i] == false) {
                flag[i] = true;
                v.push_back(nums[i]);
                recursive(pos + 1);
                v.pop_back();
                flag[i] = false;
            }
        }
    }
    //考虑i位置放哪个元素
    int n;
    vector<int> nums;
    vector<int> v;
    vector<bool> flag;
    vector<vector<int>> ans;
    
};