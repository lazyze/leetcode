class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> re(1001, 0);
        vector<int> ans;
        for (auto& it : arr1) {
            re[it]++;
        }
        for (auto& it : arr2) {
            while(re[it]) {
                ans.push_back(it);
                re[it]--;
            }
        }
        for (int i = 0; i <= 1000; i++) {
            while(re[i]) {
                ans.push_back(i);
                re[i]--;
            }
        }
        return ans;
    }
};