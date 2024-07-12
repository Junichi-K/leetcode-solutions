class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);  //i saw hints saying masks but i didn't know by the name what they meant, now hopefully i'll remmeber it forever

        int max_len = 0;

        for(int i = 0; i < n; i++) {
            for(char c : words[i]) 
                masks[i] |= 1 << (c - 'a');  //so the last bit represents a, second last represents b and so on...

            for(int j = 0; j < i; j++) {
                if(!(masks[i] & masks[j]))  //if there and result yields anything other than a 0, then they share some kind of characters
                    max_len = max(max_len, int(words[i].length() * words[j].length()));
            }
            
        }

        return max_len;
    }
};

//i was clueless. I am feeling so trash rn, don't know when will things get better. I think the older me would have been able to come up with the bit 
//solution. I don' t know what happened and where in the hell all my skills went. It all spiralled down when I fumbled my third contest. It has been just
//down and down and down from there on out