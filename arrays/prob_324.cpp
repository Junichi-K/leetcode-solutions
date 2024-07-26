class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);

        sort(sorted.begin(), sorted.end());

        for(int i = nums.size() - 1, j = 0, k = i/2 + 1; i >= 0; i--) { //the odd indices contain the largest elements in decreasing order(that is the later half of the 
                                                                        //sorted array but in decreasing order(or else there will be clashes)) the rest half of the elements
                                                                        // that is the first half of the sorted array, are the elements to be placed at the even indices 
                                                                        //again in decreasing order again to avoid clashes
            nums[i] = sorted[i & 1 ? k++ : j++];
        }

    }
};

//honestly this question taught me more about a fancy way of writing for loop instead of the actual sorting. 