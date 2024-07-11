#define MAX_SIGNS 1 
#define MAX_POINTS 1
#define MAX_E 1

class Solution {
public:
    bool isNumber(string s) {
        //check whether there is a sign at the beginning if it is, set signs = 1, otherwise too set signs = 1, if the first character is a number
        //then only either of a . or a number can appear, if point appears incremnet points
        //keep checking
        //also define a variable can_e_appear bool
        //set it to true once it can appear
        //after encountering e, incremnt e counter, then the rest of the number should be an integer

        //counters
        int signs = 0;  //if more than one signs appear then the string is invalid(with the exception that sign appears right after e which is taken 
                        //care of)
        int points = 0; //the same goes with points. This time however the string can't have more than one decimal no matter the situation
        bool can_e_appear = false;  //this is a bool which specifies if e can be added, once added it remains false as expected
        int e = 0;  //this specifies the number of e's we've encountered so far, this too can take a max value of 1
        bool numbers_after_e = false;   //if numbers have appeared after e, this this becomes true, otherwise the string ends with e, and that means 
                                        //the string is invalid
        
        if(s[0] == '-' || s[0] == '+')  //first we check if the first character is a symbol, if it is we increment our signs counter
            signs++;

        else {  //otherwise we check if either the number begins with a ., in which case it is a positve number, so we update the signs counter regardless
                //and also the points counter(remember points can't have a value more than 1 whatsoever)
            if(s[0] == '.') {
                signs++;
                points++;
            }
            
            else {  //if anything else is encountered we just gotta make sure it is within [0, 9] otherwise we can simply return false(like an 'a')
                int digit = s[0] - '0';
                if(!(digit >= 0 && digit < 10))
                    return false;

                signs++;
                can_e_appear = true;    //since we have encountered a digit, we can now add 'e' to our number
            }
        }

        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(s[i] == '.') {
                if(points == MAX_POINTS)//can't have more than 1
                    return false;
                
                if(e)   //if e has been been anything to the right of e can't have a decimal value, so we return false
                    return false;

                points++;
            }

            else if(s[i] == 'e' || s[i] == 'E') {   
                if(!can_e_appear)   //simple case
                    return false;
                if(e == MAX_E)  //if this is our second e
                    return false;
                
                e++;
                
                if(!(i + 1 == n) && (s[i + 1] == '+' || s[i + 1] == '-' || (s[i + 1] - '0' >= 0 && s[i + 1] - '0' < 10))) {
                    //here we check if the next index to the right of e is valid or nah(it can have either +,- or a digit)
                    if((s[i + 1] - '0' >= 0 && s[i + 1] - '0' < 10))
                        numbers_after_e = true; //here we store that we saw a digit right after e, (for an edge case)
                    i++;    //increment the i pointer since we have handled it here as well
                    continue;
                }

                return false;   //if none of those 3 things were encounted then it is invalid and we return false
            }

            else if((s[i] == '+' || s[i] == '-') && signs == MAX_SIGNS) //if sign is encountered and we already saw one
                return false;

            else {  
                int digit = s[i] - '0';
                if(!(digit >= 0 && digit < 10))
                    return false;

                if(e)
                    numbers_after_e = true; //this will help us when after e, we had a +/- and afterwards we'll have to set this value to true when we 
                                            //encounter a digit
                can_e_appear = true;//this is kind of repetitive assigning, but this is what I could come up with
            }
        }  

        if(points && s[n - 1] == '.') {
            if(n == 1)  //if the string is only a digit, it is invalid
                return false;

            if(s[n - 2] == '+' || s[n - 2] == '-')  //since we are at the last index and the last index is ., we gotta make sure that the left of 
                                                    //. is actually a number and not a symbol,(we don't need to worry about e since it has its
                                                    //separate handling)
                return false;
        }

        if(signs && (s[n - 1] == '+' || s[n - 1] == '-'))   //if the string ends with a sign, we can't have that so false
            return false;

        if(e && !numbers_after_e)   //e was seen but no digits were seen later
            return false;

        return true;//if all the above conditions were not met, then that means we have for ourselves a valid string  
    }
};

//forget blood, skin, testicular cancer bro, this shit is actual cancer ngl. holy shit the amount of edge cases are insane. Also now that I think about 
//it I could have had defined a MAX with value 1 but I was too focused on thinking about the implementation.