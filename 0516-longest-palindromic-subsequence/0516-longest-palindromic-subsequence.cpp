class Solution{
  public: 
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        int n=s1.length();
        reverse(s2.begin(), s2.end());
        vector<int> prev(n+1,0), cur(n+1,0);
        for(int i=0;i<=n;i++) {
            prev[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(s1[i-1] == s2[j-1]) {
                    cur[j] = 1+prev[j-1];
                } else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
};