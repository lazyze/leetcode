class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        //a * a <= x
        //最后一个 a * a <= x
        int l = 1;
        int r = x / 2;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if(long(mid) * mid <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
            //cout << l << "," << r << endl;
        }
        return l;
    }
};