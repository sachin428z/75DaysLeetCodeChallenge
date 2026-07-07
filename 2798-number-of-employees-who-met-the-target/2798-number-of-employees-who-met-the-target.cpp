class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count=0;

        for(auto it:hours) {
            if(it>=target) count++;
        }
        return count;
    }
};