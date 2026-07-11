class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long v=1LL*length*width*height; // overflow before assigning
        int b=0,h=0; // if not initalize , it will take garbage values
        
        
        if (length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000)
            b = 1;

        if (mass >= 100)
            h = 1;

         if (b == 1 && h == 1)
            return "Both";
        else if (b == 1)
            return "Bulky";
        else if (h == 1)
            return "Heavy";
        else
            return "Neither";
    }
};