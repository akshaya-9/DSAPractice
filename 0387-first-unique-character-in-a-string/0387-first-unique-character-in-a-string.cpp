class Solution {
public:
    int firstUniqChar(string s) {
       int ar[26]={0};
        for(int i=0;i<s.length();i++){
            ar[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(ar[s[i]-'a']==1) return i;
        }
        return -1;
    }
};

//TC:O(N),SC:O(1)