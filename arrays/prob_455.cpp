class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   //simple greedy approach
        sort(s.begin(), s.end());   //we simply sort both the arrays and and assign linewise so that the "gap" between cookie and greed is minimum
                                    //and this way we don't waste for example a 5 rated cookie on a 1 rated child

        int m = g.size();
        int n = s.size();

        int i = 0, j = 0;

        int result = 0;

        while(i < m && j < n) {
            if(g[i] <= s[j]) {
                result++;
                i++;
                j++;
            }

            else {
                j++;
            }
        }

        return result;
    }
};

//not a fan of this question if you ask me 