class Solution {
public:
    int reverseBits(int n) {
        int result =0;
        for(int i=0;i<32;i++) {
            result = result<<1; // left shift to make space for LSB
            result = result  | (n&1); // add LSB to result
            n = n>>1; // remove LSB from n
        }
        return result;
    }
};