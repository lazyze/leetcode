class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int j = height.size() - 1;
        int lhight = 0;
        for (int i = 0; i < j; i++) {
            if (height[i] < lhight) continue;
            ret = max(ret, min(height[i], height[j]) * (j - i));
            while (height[i] > height[j]) {
                int tmp = height[j];
                while (i < j && height[j] <= tmp) {
                    j--;
                }
                if (i == j) break;
                ret = max(ret, min(height[i], height[j]) * (j - i));
            } 
            lhight = height[i];
        }
        return ret;
    }
};