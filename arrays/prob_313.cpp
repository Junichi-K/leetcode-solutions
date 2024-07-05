class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        vector<long> position(k, 0);//each index in this array is the index at result that each prime at index has "reached" in the ugly number hierarchy
        vector<long> result(n); //i'th index holds the i+1'th ugly number
        result[0] = 1;  //the first ugly number is 1 so we simply define that ourselves

        for(int i = 1; i < n; i++) {
            long temp = INT_MAX;//in the end this variable will hold our i+1'th ugly number. We make use of min() so we use int_max here

            for(int j = 0; j < k; j++) 
                temp = min(temp, result[position[j]] * primes[j]);  //finding the minimum by iterating over all the primes multiplied by their respective
                                                                    //hierarchy "distance" in the ugly "road". AT the end of this loop temp holds the i+1'
                                                                    //th ugly number

            for(int j = 0; j < k; j++)
                position[j] += temp == (result[position[j]] * primes[j]);   //we increment the "hierarchy" of each prime that would give the current number
                                                                            //which helps us with not inserting duplicates in the result array

            result[i] = temp;   //after updating positions, we can insert the previously computed ugly number stored in temp
        }

        return result[n - 1];
    }
};

//yeah so I kinda could figure out the solution, like I needed a pointer array, to point to the "position" each of the prime was in, however instead of
//pointing to result array, I brain fucked by pointing to another array like 2 * 2, 7 * 7, 13 * 13 and so on. I couldn't really compute that I needed 
//to point to result array itself 