class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        stack<pair<int,int>> rd;
        int weight;
        for (int i = 0; i < heights.size(); i++) {
            weight = 0;
            while (!rd.empty() && rd.top().first >= heights[i]) {
                weight += rd.top().second;
                ret = max(weight * rd.top().first, ret);
                rd.pop();
            }
            rd.push(make_pair(heights[i], weight + 1));
        }
        return ret;
    }
};