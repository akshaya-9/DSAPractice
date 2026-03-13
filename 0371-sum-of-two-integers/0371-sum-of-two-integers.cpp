class Solution {
public:
    int getSum(int a, int b) {
        int temp=0;
        while(b!=0) {
           temp = a&b;
           a = a^b;
           b = temp<<1;
        }
        return a;
    }
};