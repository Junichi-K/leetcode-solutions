class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first_max = LONG_MIN;
        long second_max = LONG_MIN;
        long third_max = LONG_MIN;

        //unordered_set<int> dickfart_edgecase;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > first_max) {
                third_max = second_max;
                second_max = first_max;
                first_max = nums[i];

                //dickfart_edgecase.insert(nums[i]);
            }

            else if(nums[i] > second_max && nums[i] != first_max) {
                third_max = second_max;
                second_max = nums[i];

                //dickfart_edgecase.insert(nums[i]);
            }

            else if(nums[i] > third_max && nums[i] != second_max && nums[i] != first_max) {
                third_max = nums[i];
                
                //dickfart_edgecase.insert(nums[i]);
            }
        }

        /*if(dickfart_edgecase.size() < 3)
            return first_max;*/

        if(third_max == LONG_MIN)
            return first_max;

        return third_max;
    }
};

//you can see how pissed off I was handling the stupid edge case, then found the usage of LONG_MIN. However the positive that can be taken out of this 
//problem is that I instantly could come up with the 3 variable solution and I was typing and I was typing hard.  Like no pause just like the anime 
//programmer lmao.