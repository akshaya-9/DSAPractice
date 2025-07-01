class Solution {
public:
    int possibleStringCount(string word) {
          int cnt=0, pos_str=1;
          char prev;
          for(int i=0;i<word.length(); i++){
             if(prev == word[i]) {
                cnt++;
             } else {
                pos_str += cnt;
                cnt =0;
                prev= word[i];
             }
             
          }
          return pos_str+cnt;
    }
};


// TC:O(N), SC:O(1)