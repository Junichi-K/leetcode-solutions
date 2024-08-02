class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;

        for(int i = s.length() - 1; i >= 0; i--) {  //we start from the end of the string, this way the first segment can have k or less than k characters
            if(s[i] != '-') {
                s[i] = toupper(s[i]);   //this function is so shit, I still don't know what is it's return type. This is the same way I used it in my own code, and it gave
                                        //some stupid false results
            
                result += s[i];
                count++;

                if(count == k) {    //as soon as the amount of elements inserted becomes equal to k, we add a hyphen and reset count
                    result += '-';
                    count = 0;
                }
            }
        }

        if(!result.empty() && result.back() == '-') //removing any leading hyphens
            result.pop_back();

        reverse(result.begin(), result.end());  //reversing the list since we added in the beginning

        return result;
    }
};

//okay so this made me remember again why strings are a pain in the ass. Since I was traversing the string in reverse, I had to append characters to the beginning of 
//result and as a result, it first caused MLE, my bad, it has happened before, should have been cautious, whatever, then used insert with result.begin() and then found that
//toupper returns a int???? which led to false results. then did static_cast using ? : if not number, then toupper else append as it is. This however gave me a horrible 
//runtime like literally shithole runtime. Whatever then found this solution. It makes use of the better in place += and then reverse the string to get the correct answer