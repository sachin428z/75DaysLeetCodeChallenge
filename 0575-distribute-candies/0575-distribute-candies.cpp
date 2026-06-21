class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());
        vector<int>v;

        v.push_back(candyType[0]);
        int i=1;
        int j = 0;
        while(i < n){
            
            if(candyType[i] == v[j]) i++;
            else{
                v.push_back(candyType[i]);
                j++;
                i++;
            }
        }

        if(v.size() > n/2) return n/2;
        else return v.size();

    }
};