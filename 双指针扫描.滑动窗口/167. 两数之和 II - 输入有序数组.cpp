class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size() - 1;
        while (begin < end) {
            if (numbers[begin] + numbers[end] > target) {
                end--;
            } else if (numbers[begin] + numbers[end] < target) {
                begin++;
            } else return {begin + 1, end + 1};
        }
        return {};
    }
};