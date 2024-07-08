class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last_index[26]; //the last appearance of each character in the given string

        int n = s.length();
        for(int i = 0; i < n; i++) 
            last_index[s[i] - 'a'] = i;
        
        int present[26];    //keeps track of which character are in the stack at a given point of time
        stack<char> bucket; //we use this for sequentiality maintaining

        for(int i = 0; i < n; i++) {
            int current_char = s[i] - 'a';

            if(present[current_char])   //if the current character is already in our stack, we can't push it so we simply skip it
                continue;

            while(!bucket.empty() && s[i] < bucket.top() && i < last_index[bucket.top() - 'a']) {   //as long as the stack is empty and the current 
                                                                                                    //character is smaller than the one on top of stack 
                                                                                                    //we try to "remove" it in order to hopefully obtain 
                                                                                                    //a better lexicographical string. For this we have to 
                                                                                                    //check one condition we have to follow for us to 
                                                                                                    //remove the given character. If the character exists 
                                                                                                    //later on in the given string, then we can for sure 
                                                                                                    //remove it otherwise we are unfortunately have to let it 
                                                                                                    //be
                present[bucket.top() - 'a'] = 0;//updating the data structures simultaneously
                                                
                bucket.pop();
            }

            present[current_char] = 1;  //after we have reached a character we can't pop or the stack became empty, we push our current character 
            bucket.push(s[i]);
        }

        string result = ""; //just access the stack string and reverse it because of lifo
        while(!bucket.empty()) {
            result = result + bucket.top();
            bucket.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};