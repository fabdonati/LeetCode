/*
  322. Coin Change
    Medium

    You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    Example 1:
    Input: coins = [1, 2, 5], amount = 11
    Output: 3 
    Explanation: 11 = 5 + 5 + 1

    Example 2:
    Input: coins = [2], amount = 3
    Output: -1

    Note:
    You may assume that you have an infinite number of each kind of coin.
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public: 


  int coinChange(vector<int>& coins, int amount) {
    // returns zero if amount is <=0
    if (amount < 1) return 0;

    // initializes dp array
    vector<int> dp(amount + 1);
    return coinChange(coins, amount, dp);
  }

  // bottom up approach (fills all gaps)
  int leastCoint(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

private:
  int coinChange(vector<int>& coins, int remainder, vector<int>& dp) {
    if (remainder < 0) return -1;
    if (remainder == 0) return 0;

    // if it has not a cached solution, calculate it
    if (dp[remainder] != 0) return dp[remainder];

    int minimum = INT_MAX;
    for (int coin : coins) {
      // calculates the number of coins needed to make it to remainder - coin
      int changeResult = coinChange(coins, remainder - coin, dp);
      // checks if number of needed coins is larger than 0 and smaller than the minimum
      if (changeResult >= 0 && changeResult < minimum) minimum = 1 + changeResult;
    }
    // -1 occurs when none of the 
    dp[remainder] = (minimum == INT_MAX) ? -1 : minimum;
    return dp[remainder];
  }
};


int main() {
  vector<int> coins = {1,2,5};
  int amount = 11;

  Solution solution;
  cout << "Coins available = "; for_each(coins.begin(), coins.end(), [] (const int c) {cout << c << " ";}); // lambda function to print all members of a vector
  cout << "\nLeast number of coins to make " << amount <<  " = " << solution.coinChange(coins, amount) << endl;

  return 0;
}