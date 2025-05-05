class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int current_sum =0, total;
        int n = cardPoints.size();
        int min_sum = INT_MAX;
        int window_size = n-k;
        for(int i=0; i< n;i++) {
            total += cardPoints[i];
        }
        std::cout<<"total "<<total<<"\n";
        for(int i=0;i<window_size;i++) {
            current_sum += cardPoints[i];
        }
        min_sum = current_sum;
        for(int i=window_size;i<n;i++) {
            current_sum += cardPoints[i];
            current_sum -= cardPoints[i-window_size];
            min_sum = min(min_sum, current_sum);
        }

        return total-min_sum;
    }
};