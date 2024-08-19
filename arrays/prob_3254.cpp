class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = 1;
        int prev_wrong = -1;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1] + 1) {
                prev_wrong = i;
                dp[i] = 0;
            }

            else if(i < k - 1)
                dp[i] = 1;

            else if(i - k + 1 >= prev_wrong){
                dp[i] = 1;
            }
        }

        vector<int> result;
        for(int i = k - 1; i < n; i++) {
            if(dp[i])
                result.push_back(nums[i]);

            else
                result.push_back(-1);
        }

        return result;
    }
};