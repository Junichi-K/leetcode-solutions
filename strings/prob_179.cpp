bool comparator(const string &a, const string &b) {
    return a + b > b + a;   //the base case of comparing two strings as they will have 2 combinations and we return bool on the basis of that
}

class Solution {
public:
    static bool compare(const string &a, const string &b) { //just learnt that sort() needs a static function or one straight up outside the class
                                                            //that is it should not depend on the presence of an object
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numbers; //will store the numbers as strings in the "sorted" manner

        for(int num : nums) 
            numbers.push_back(to_string(num));

        sort(numbers.begin(), numbers.end(), comparator /* or comapre*/);   //we sort our list according to the comparator function above. This way 
                                                                            //digits like 9, 8 end up in the beginning and ones with smaller "weight"
                                                                            //go back to the end

        string result = "";
        for(string s : numbers) 
            result += s;

        if(result[0] == '0')
            return "0";

        return result;
    
    }
};

//again could figure out that some sort of a sorting was needed but couldn't think about the base case