class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        for(int i:nums) {
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mp) {
            pq.push({i.second,i.first});
        }
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};