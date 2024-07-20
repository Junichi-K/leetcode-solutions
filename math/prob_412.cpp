class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for(int i = 1; i <= n; i++) {
            if(!(i % 3) && !(i % 5)) {
                result[i - 1] = "FizzBuzz";
                continue;
            }

            else if(!(i % 3)) {
                result[i - 1] = "Fizz";
                continue;
            }

            else if(!(i % 5)) {
                result[i - 1] = "Buzz";
                continue;
            }

            else
                result[i - 1] = to_string(i);
        }

        return result;
    }
};

//this surely has to be a joke right. This hands down has to be the easiest quetion on LC
