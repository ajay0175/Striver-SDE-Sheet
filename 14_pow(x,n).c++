class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long a = n;
        
        if(a < 0)
            a *= -1;
        
        while(a)
        {
            if(a % 2)
            {
                ans *= x;
                a -= 1;
            }
            else
            {
                x *= x;
                a /= 2;
            }
        }
        
        return (n < 0 ? (double)(1.0) / (double)ans : ans);
    }
};

/*
    TC => O(LOG N)
    SC => O(1);
*/