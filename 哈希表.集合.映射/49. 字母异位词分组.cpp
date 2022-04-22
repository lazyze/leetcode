class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rd;
        vector<vector<string>> ret;
        string tmp;
        for (auto& it : strs) {
            tmp = it;
            sort(it.begin(), it.end());
            rd[it].push_back(tmp);
        }
        for (auto& it : rd){
            ret.push_back(it.second);
        }
        return ret;
    }
};