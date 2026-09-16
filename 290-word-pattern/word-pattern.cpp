class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        set<string> used;
        int j=0;
        for(int i=0;i<pattern.length();i++){
            string word="";
            if(j>=s.length()){
                return false;
            }
            while(j<s.length() && s[j]!=' '){
                word += s[j];
                j++;
            }
            j = j+1;
            cout<<"word "<<word<<endl;
            if(m.find(pattern[i])==m.end()){
                if(used.find(word)!=used.end()){
                    return false;
                }
                m[pattern[i]] = word;
                used.insert(word);
            } else if(m[pattern[i]]!=word){
                return false;
            }
        }
        if(j<s.length()) return false;
        return true;
    }
};