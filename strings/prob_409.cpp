class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 58> characters = {0};//the characters are represented using ascii as follows. 'A' starts at 65 then there are 26 uppercase alphabets
                                        //then there are 6 random symbols(don't ask me why) and then come the 26 lowercase letters. So in total there 
                                        //are 26 letters and hence in total there are 26 + 26 + 6 = 58 range of ascii values wherein the middle 6 will 
                                        //always be zero no matter what

        int n = s.length();
        for(int i = 0; i < n; i++) 
            characters[s[i] - 'A']++;   //calculating frequencies
        
        int result = 0; //our answer
        int largest_odd = 0;//which character has the largest odd apperances, we will make this the center of or palindrome  
        int largest_odd_index;  

        for(int i = 0; i < 58; i++)
            if(characters[i] % 2 && characters[i] > largest_odd) {
                largest_odd = characters[i];
                largest_odd_index = i;
            }

        if(largest_odd > 0) //there might be a possibility that all characters have even appearences so just to make sure
            characters[largest_odd_index] = 0;

        result += largest_odd;  


        for(int i = 0; i < 58; i++) {
            if(characters[i] % 2 == 0)  //if the frequency of a particular character is even, we can take all of them, just add them to the left and right
                                        //of the current palindrome formec
                result += characters[i];

            else//otherwise if we see an odd number of characters, we take the maximum possible even characters to add to our palindrome
                result += characters[i] - 1;
        }

        return result;
    }
};