class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> dif(n + 1, 0);
        int first, last, seats;
        for (auto& it : bookings) {
            first = it[0];
            last = it[1];
            seats = it[2];
            dif[first - 1] += seats;
            dif[last] -= seats;
        }
        vector<int> sums(n, 0);
        sums[0] = dif[0];
        for (int i = 1; i < n; i++) {
            sums[i] = dif[i] + sums[i - 1];
        }
        return sums;
    }
};