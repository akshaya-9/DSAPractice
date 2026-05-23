class Solution {
private:
long long can_eat(vector<int>& piles, int k){
    long long cnt=0;
    for(int i=0;i<piles.size();i++){
        cnt += ceil(double(piles[i])/double(k));
    }
    return cnt;
}
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int mx =*max_element(piles.begin(),piles.end());
        int l=1, h=mx;
        while(l<=h){
            int mid = (l+h)/2;
            long long total= can_eat(piles, mid);
            if(total<=hr){
                h=mid-1;
            } else{
                l=mid+1;
            }
        }
        return l;
    }
};