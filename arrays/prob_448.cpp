class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for(int n : nums) {
            if(nums[abs(n) - 1] > 0)//whatever number we see we set that specific absolute index value(considering 1-indexing) equal to its own negative
                nums[abs(n) - 1] *= -1; //this way we know what numbers we have seen when we traverse the array a second time
        }

        int i = 0;
        for(int j = 0; j < nums.size(); j++) {  //the indexes that are negative are present in the array and the values that are positive mean
                                                //that those index values were not present in the array. So we simply modify in place in the array
            if(nums[j] > 0) {
                nums[i] = j + 1;
                i++;
            }
        }

        nums.resize(i); //delete all the other elements

        return nums;
    }
};