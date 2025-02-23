class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        int maxfreq = INT_MIN, cnt=0;
        for(auto i:m) {
           int freq = i.second;
           if(freq> maxfreq) {
               maxfreq = freq;
               cnt =1;
           }
           else if(freq == maxfreq) {
                cnt ++;
           }
        }
        return cnt*maxfreq;
    }
};