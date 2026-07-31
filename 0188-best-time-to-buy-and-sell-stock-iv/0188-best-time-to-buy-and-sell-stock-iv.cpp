// dp[j][i] = i일까지의 최대 수익, j 거래횟수
// dp[k][prices.size()] ->답
// 주식없음 -> 어제도 없었거나, 오늘 판 경우
// 주식있음 -> 어제도 있었거나, 오늘 산 경우

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int j = 1; j <= k; j++) {
            // 주식있음 -> 첫째 날 주식을 산 상태로 초기화
            int max_diff = -prices[0]; 
            for (int i = 1; i < n; i++) {
                // 주식없음 -> 어제도 없었거나(dp[j][i-1]), 오늘 판 경우(prices[i] + max_diff)
                dp[j][i] = max(dp[j][i - 1], prices[i] + max_diff);
                
                // 주식있음(다음 날 계산을 위해 갱신) -> 어제도 있었거나(max_diff 유지), 오늘 새로 산 경우(dp[j-1][i] - prices[i])
                max_diff = max(max_diff, dp[j - 1][i] - prices[i]);
            }
        }
        
        // dp[k][prices.size() - 1] -> 답
        return dp[k][n - 1];
    }
};