class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high) {
            // Find mid point
            int mid = (low + high) / 2;

            // If mid element is greater than next
            if (nums[mid] > nums[mid + 1]) {
                // Move to left half
                high = mid;
            } else {
                // Move to right half
                low = mid + 1;
            }
        }

        // Return peak index
        return  low;
    }
};