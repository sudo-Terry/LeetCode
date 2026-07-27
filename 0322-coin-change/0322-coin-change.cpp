
// dp[n] = min(dp[n - coins[0]], ... dp[n - coins[k]]) + 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // amount + 1이 INF 역할
        vector<int> dp(amount + 1, amount + 1);
        // 내림차순
        sort(coins.begin(), coins.end(), greater<int>());
        dp[0] = 0;

        // bottom-up
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // bottom-up으로 초기화되지 않음
        if(dp[amount] > amount) return -1;

        return dp[amount];
    }
};