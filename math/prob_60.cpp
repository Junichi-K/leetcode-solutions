/*class Solution {
private:
    vector<int> present;
    string result;
public:
    string getPermutation(int n, int k) {
        present.resize(n, 0);
        result = "";

        helper_function(n, k);

        return result;
    }

    void helper_function(int current_n, int left_value_k) {
        if(current_n == 1) {
            for(int i = 0; i < present.size(); i++) {
                if(!present[i]) {
                    present[i] = 1;
                    result = result + char(i + 1);
                    return;
                }
            }
        }
        int number = 1;
        while(number * tgamma(current_n) < left_value_k) 
            number++;
        
        int i;
        for(i = 0; i < number; i++) {
            if(present[i])
                i++;
        }

        present[i - 1] = 1;
        result = result + char(i);

        helper_function(current_n - 1, left_value_k - (number - 1) * tgamma(current_n));
        
    }   
};

MY SOLUTION. ALMOST HAD THIS SHIT DOWN. JUST KEPT FUCKING WITH 1-INDEXING AND PAID THE PRICE. IT IS FIXABLE BUT THE ONE I FOUND IS A LOT CLEARNER*/

class Solution {
public:
    string getPermutation(int n, int k) {
        //so the approach here is you first write down the permutations and find a pattern. Suppose n = 4 and write them down sequentially. What you'll 
        //find is that the first 3! numbers begin with 1, the next 3! numbers begin with 2 and so on.... and we apply this same approach to the rest of 
        //the numbers(that the first 2! numbers would begin with the first of the 3 numbers left, the next 2! numbers would begin with the second of the 3 
        //numbers left and so on)
        int fact[] = {1,1,2,6,24,120,720,5040,40320,362880};

        vector<int> set;//helps us in keeping track of what needs to be added and also their order
        for(int i = 1; i <= n; i++) 
            set.push_back(i);
        
        k--;    //will help with 0-indexing

        string result = "";
        while(n > 0) {
            int index = k/fact[n - 1];  //this is essentially performing what I wrote earlier(0 means first number, 1 means second number in set and so on)
            result += set[index] + '0';
            set.erase(set.begin() + index); //since the number has now been added it is appropriately removed

            k %= fact[n - 1];   //updating k to work with the next iteration
            n--;
        }

        return result;
    }
};

//I left my own soultion above for comparison and to see how much close it was to the actual solution