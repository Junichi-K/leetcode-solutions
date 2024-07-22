class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length())
            return addStrings(num2, num1);
        
        string result = "";
        int temp;
        int carry = 0;

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while(i >= 0 && j >= 0) {
            temp = (num1[i] - '0') + (num2[j] - '0') + carry;

            result = to_string(temp % 10) + result;
            carry = temp/10;

            i--;
            j--;
        }

        while(i >= 0) {
            temp = (num1[i] - '0') + carry;
            result = to_string(temp % 10) + result;
            carry = temp/10;
            i--;
        }

        if(carry)
            result = to_string(carry) + result;

        return result;
    }
};

//mostly a simple code. However I made a few fuckups in that I didn't knew that < compared strings lexicographically.(I was sceptical earlier in some 
//questions too but I think I forgot that I read that). Anyway, I just had to make sure the length of the first number is the larger one or atleast equal
//to the other number(doesn't require me to do redundant code)