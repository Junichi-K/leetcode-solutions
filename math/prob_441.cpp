class Solution {
public:
    int arrangeCoins(int n) {
        long number_of_coins;

        int left = 1, right = 500000;   //both these numbers represent the number of rows
        int mid;//we use binary search
        while(left < right) {
            mid = (left + right)/2;

            if(consec(mid) <= n && consec(mid + 1) > n) //it means the coins "end" at mid row
                return mid;

            else if(consec(mid) < n)
                left = mid;

            else
                right = mid;
        }

        return 0;
    }

    long consec(int number) {
        return ((long)number * (long)(number + 1))/2;
    }
};