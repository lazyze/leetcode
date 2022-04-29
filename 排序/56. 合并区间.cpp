//排序法
class cmp {
//private:
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

struct cmpS{
//public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
} ;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> data;
        for (auto& it : intervals) {
            int a = it[0];
            int b = it[1];
            data.push_back(make_pair(a, b));
        }
        // sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int,int>& b) {
        //     return a.first < b.first || (a.first == b.first && a.second < b.second);
        // }
        // );
        sort(data.begin(), data.end(), cmpS());
        //sort(data.begin(), data.end(), cmp());
        int l;
        int r;
        for (int i = 0; i < data.size(); i++) {
            if (i == 0) {
                l = data[i].first;
                r = data[i].second;
            } else {
                if (data[i].first > r) {
                    ans.push_back({l, r});
                    l = data[i].first;
                    r = data[i].second;
                } else {
                    r = max(r, data[i].second);
                }
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};