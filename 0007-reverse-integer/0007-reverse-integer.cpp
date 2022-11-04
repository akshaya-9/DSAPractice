class Solution {
public:
    int reverse(int x) {
        bool neg = x<0;
        int x1=abs(x);
        int ans=0;
        while(x1>0){
            if(ans> INT_MAX/10 || ans<INT_MIN/10) return 0;
            ans = ans*10 + x1%10;
            x1 = x1/10;
        }
        if(neg) return -1*ans;
        return ans;
    }
};


TC: O(logx), SC:O(1)
