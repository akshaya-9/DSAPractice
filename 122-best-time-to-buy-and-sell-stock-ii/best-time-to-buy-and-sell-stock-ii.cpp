class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[0], ans=0, sum=0;
        for(int i=1;i<prices.size();i++){
            m = min(m, prices[i]);
            if(prices[i] > m) { sum = prices[i]-m;
            ans = ans + sum;
            m = prices[i];
            }
        }
        return ans;
    }
};

//TC:O(N)
//SC:O(1)