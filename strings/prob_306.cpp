class Solution {
private:
    bool helper_function(const string &first, const string &second,const string &remainder) {
        if((first.size() > 1 && first[0] == '0') || (second.size() > 1 && second[0] == '0'))//if numbers are more than 1 digit and first digit is 0
                                                                                            //then that means they have leading zeroes(remember we still 
                                                                                            //have to consider 0 in itself as 101 can be an additive no)
            return false;

        string sum = to_string(stoll(first) + stoll(second));   //we "add" the two numbers
        int size = sum.length();    

        if(sum == remainder)//if this is the case, then voila, we have atleast 3 numbers(first, second and remainder, which satisfy the additive condition)
            return true;

        else if(size == remainder.size() || remainder.substr(0, size) != sum)
        //if their sizes are the same, we can't extend remainder further, AND they don't match otherwise above block would execute so we return false. 
        //OR if their sizes don't match AND sum doesn't match the beginning of the remainder of the string, this again violates the additive property
        //and we simply return a false as there is no point going further
            return false;

        return helper_function(second, sum, remainder.substr(size));    //otherwise our second number, becomes the first, the beginning part of remainder
                                                                        //which was equal to sum(as confirmed by the above else if block) becomes our 
                                                                        //second and we update our remainder substring
    }

public:
    bool isAdditiveNumber(string num) {
        const int n = num.length();
        if(n <= 2)  //since we gotta have atleast 3 numbers in the additive sequence, so all strings with length less than 2 are rejected straight away
            return false; 

        for(int i = 1; i <= n/2; i++)
            for(int j = 1; j <= (n - i)/2; j++)
            //now here is the interesting part, (I kinda figured it out while writing my own solution too). Why are we only iterating halfway? First let's 
            //understand for i. We got two cases 1. say n is even. Then the max length of the first_string(we're using i to form the fist number in the
            //additive sequence) would be exactly half of the total string. Now this makes complete sense because the second number would atleast have 1 
            //digit, and there is no way the rest of the digits make up the sum of the first 2. Lets us understand this with an example. say n = 6. So the 
            //max length of the first number can be 3. If we take into account the min size of the second number as well say 1.  So now the two numbers make 
            //up 4 digits of the 6 originally. And there is no way the sum of a 3 digit and a 1 digit would give a 2 digit number(both are positive) So this 
            //means there is definitely no point in increasing the size of the first number. --This is the behaviour of n/2 for even numbers
            //Let us take odd n for an example. Say n = 7. So again max 3 would be the size of the first number. Even after taking the minimum size of the 
            //second number, we are at a total of 4 digits. and left with 3 digits. Again there is no point in increasing the length of the first number any 
            //further, cuz it would be 4 digit and a 1 digit, leaving 2 digits for the remainder. Again no way a 4 digit and a 1 digit add up to give a 2 digit
            //Now coming onto the j part. Well the logic is kinda similar. The mininum size of the first number can be 1, Again take odd and even n. n = 6. 
            //Suppose we take a 1 digit first number, Leaving us with 5 digits. The max length of second can be (n - 1)/2 so 5/2 which gives us 2. Again 1+2=3
            //Now you might be asking but hey so there are 3 digits left and we have a 1 digit and a 2 digit. That doesn't make sense, cuz the addition of a 1 
            //and a 2 digit can still give a 3 digit number and why not extend it one more time. See it this way, if we take n-i/2 + 1. Then the second number
            //can have a max 3 digits in that case. leaving us with 6 - 3 + 1 = 2 digits. Now again there is no way their sum can give us a 2 digit number
            //So we stopped checking at n-i/2. Lastly, n = 7, first number can be a single digit, leaving us with 6, n-i/2 gives us 3. The max length of
            //second number can be 3 digits. Leaving us with 3 digits. So again we only iterate till valid addition is possible. We move any further, we get a 
            //single digit and a 4 digit to add to a 2 digit which is not possible. 
            //also this logic has to be understood for the max, min cases like above, in other cases, it doesn't really matter, it will be terminated by 
            //the function above
                if(helper_function(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;

        return false;
    }

};

//I half figured out the solution by myself. given the accep rate, this is foshure a hard problem so I am satisfied with my performance(we will get 
//fully solving by ourselves someday)