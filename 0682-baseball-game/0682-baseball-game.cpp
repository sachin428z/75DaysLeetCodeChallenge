class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        for(auto op: operations) {
            if(op=="+") {
                int top=stack.back(); stack.pop_back();
                int secondtop=stack.back();
                stack.push_back(top);
                int add=top+secondtop;
                stack.push_back(add);

            } else if(op=="D") {
                stack.push_back(2*stack.back());
            } else if(op=="C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(op)); //String TO Integer.
            }
        }
        int sum = 0;
        for (int x : stack) {
            sum += x;
        }
        return sum;
        // return accumulate(stack.begin(),stack.end(),0); //sum of all stack, initially sum is 0
    }
};