class Solution {
public:
    int findComplement(int num) {
        if(!num)//we handle this case prematurely otherwise our code returns 0 itself
            return 1;

        int result = 0;
        int i = 31; //we start off at the msp of a 32 bit int

        while(i >= 0 && !(num & (1 << i)))  //getting i to the msb
            i--;

        while(i >= 0) {
            if(!(num & (1 << i)))   //if the i'th bit of num is zero
                result |= 1 << i;   //set that specific bit in result equal to one

            i--;
        }

        return result;
    }
};

//the only tricky part was avoiding the leading zeroes. My original code had flaw with assigning value to result (~ is very tricky to use)	