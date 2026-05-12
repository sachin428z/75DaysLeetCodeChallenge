// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first_bad = 0;
        int low = 1, high = n;
        while (low <= high) {
            int mid = low - (low - high) / 2;
            if (isBadVersion(mid) == true) {
                first_bad = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return first_bad;
    }
};