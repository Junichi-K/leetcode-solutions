
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        int found = 0;

        for(int i = n/2; i > 0; i--) {  //we start off by creating strings of length half of what is given to us originally
            if(n % i != 0)  // if the string can't be divided into substrings of length i, no point in going further
                continue;
            
            string temp = s.substr(0, i);

            for(int j = i; j < n; j += i) {
                string temp2 = s.substr(j, i);
                if(temp != temp2) {
                    break;
                }

                if((j + i) == n) {  //if we reach till end of string, return true
                    return true;
                }
            }

        }

        return false;
   }
};