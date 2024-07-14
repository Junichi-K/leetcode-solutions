class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_index = 0;
        int s_index = 0;

        int n = s.length();
        int m = t.length();

        while(s_index < n && t_index < m) {
            if(s[s_index] == t[t_index]) {
                s_index++;
                t_index++;
            }

            else 
                t_index++;
        }

        if(s_index == n)
            return true;

        return false; 
    }
};

//yeah an easy ahh problem. At first I read it like substring and I thought oh this seems to be a one liner using the .find method. But then I realized 
//I needed to find a subsequence. Then I was like maybe I needed a dp cache(i think it will use 2d dp but might work out with 1d I'm not too sure). But 
//then I thought about using two pointers, and found out that yeah it actually works, and so wrote it out checked it with a couple cases found out that 
//it works and then submitted and voila no problems and 0ms first try. (Confidence is getting back up for sure, step by step but I'll take it)