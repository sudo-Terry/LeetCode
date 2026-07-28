// dp[i] -> nums[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        // 모든 원소는 자기 자신만으로 길이 1인 부분 수열을 가질 수 있으므로 1로 초기화
        vector<int> dp(n, 1);
        int maxLength = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // 현재 원소(nums[i])가 이전 원소(nums[j])보다 큰 경우에만 증가 수열 성립
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // 전체 수열 중 가장 긴 길이를 갱신
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};