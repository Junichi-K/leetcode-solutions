class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        int first, second;
        
        for(int i = 0; i < 32; i++) {
            first = x & 1;
            second = y & 1;

            result += first ^ second;

            x >>= 1;
            y >>= 1;
        }

        return result;
    }
};