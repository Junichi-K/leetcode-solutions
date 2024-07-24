class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        int n = coins.size();
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {  //for each amount we consider all the coins
            for(int j = 0; j < n; j++) {
                int number = i - coins[j];
                if(number < 0)  //number is the amount of money left to add. if lesser than zero, we don't consider the coin 
                    continue;

                dp[i] = min(dp[i], 1 + dp[number]); //we consider a coin, subtract from the total amount, and then check the corressponding dp cache
            }
        }

        if(dp[amount] == amount + 1)
            return - 1;

        return dp[amount];
    }
};

//i just have such a poo poo brain with limited fov. I first tried greedy, didn't work, whatever knew this was a dp problem by then. Then started to 
//think of the dp solution and thought a dp cache of coins.size() would be required. Tried as hard to think of how it could work. But obviously couldn't
//as there is no such solution. But one thing I have to remember is WHENEVER I HAVE A DP PROBLEM, JUST DRAW OUT THE DECISION TREE AND
//TRY TO FIND THE SUBPROBLEMS AND THAT REALLY IS ALL THERE IS TO DP PROBLEMS, even though it may seem
//trivial and obvious and easy, it MIGHT help you "see" the pattern. I repeat DP = DRAW TREE and you'll come up with the solution. (dp ain't that hard)