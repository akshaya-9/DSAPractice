class Solution {
private:
    void helper(string digits, vector<string> mapping, vector<string>& ans, int idx,string current) {
        if(idx==digits.length()) {
            ans.push_back(current);
            return;
        }
        int digit = digits[idx]-'0';
        for(int i=0;i<mapping[digit].length();i++) {
             helper(digits, mapping, ans, idx+1, current+mapping[digit][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s= "";
        helper(digits, mapping, ans,0,s);
        return ans;
    }
};