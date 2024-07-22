class Solution {
public:
    int countSegments(string s) {
        if(s.length() == 0)
            return 0;
        
        int spaces = 0;
        bool on_word = false;

        for(int i = 0; i < s.length(); i++) {
            if(!on_word && s[i] != ' ') 
                on_word = true;
            

            else if(on_word && s[i] == ' ') {
                on_word = false;
                spaces++;
            }
        }

        if(s[s.length() - 1] != ' ')
            return spaces + 1;

        return spaces;
    }
};

//well the thing right now is I can type out the easy questions really really quick but I get some small errors which I overlook is what I'm tryna fix. 
//Write code as fast as possible but at the same time, don't let any error creep in