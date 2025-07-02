class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> s;
        int n=nums.length();
        if(k==n) return "0";
        for(int i=0;i<n;i++) {
            while(!s.empty() && k>0 && s.top()>nums[i]) {
                s.pop();
                k--;
            }
            s.push(nums[i]);
        }
        while(k>0 && !s.empty()) {
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};