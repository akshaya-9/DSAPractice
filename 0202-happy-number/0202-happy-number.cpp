class Solution {
private:
   int check(int n) {
    int sum=0;
     while(n>0) {
        int m = n%10;
        sum += m*m;
        n=n/10;
     }
     return sum;
   }
public:
    bool isHappy(int n) {
        int sum=0;
        set<int> s;
        while(s.find(n)==s.end()){
            s.insert(n);
            n  = check(n);
            if(n==1) return true;
        }
        return false;
    }
};