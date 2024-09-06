class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int n = s.length();

        for(int i = 0; i < n; i += k) {
            string temp = s.substr(i, k);

            result.push_back('a' + sum(temp) % 26);
        }

        return result;
    }

    int sum(string s) {
        int result = 0; 

        for(char c : s) {
            result += c - 'a';
        }

        return result;
    }
};