class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0,down=0,right=0,left=0;
        int n=moves.size();

        for(char ch: moves) {
            if(ch=='U') up++;
            else if(ch=='D') down++;
            else if(ch=='R') right++;
            else left++;

        }
        if(up-down==0 && right-left == 0) return true;
        else return false;
        }
};