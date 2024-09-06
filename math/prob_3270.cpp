#include<algorithm>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;

        for(int i = 0; i < 4; i++) {
            key = min(min(num1 % 10, num2 % 10), num3 % 10) * pow(10, i) + key;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }

        return key;
    }
};