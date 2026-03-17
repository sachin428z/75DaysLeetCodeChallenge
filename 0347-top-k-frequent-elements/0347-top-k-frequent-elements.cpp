#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        
        // Step 1: Count frequency
        for(int num : nums) {
            freq[num]++;
        }
        
        // Min heap (frequency, number)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;
        
        // Step 2: Push into heap
        for(auto &it : freq) {
            minHeap.push({it.second, it.first});
            
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Step 3: Extract result
        vector<int> result;
        
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};
