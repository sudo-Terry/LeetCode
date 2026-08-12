class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0; // 현재까지 도달할 수 있는 최대 인덱스
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // 현재 인덱스가 도달할 수 있는 최대 인덱스보다 크다
            if (i > max_reach) {
                return false;
            }
            
            // 기존에 도달 가능한 최대 인덱스와 현재 위치에서 점프해서 갈 수 있는 인덱스 중 큰 값으로 갱신
            max_reach = max(max_reach, i + nums[i]);
            
            // 만약 도달할 수 있는 최대 인덱스가 배열의 마지막 위치 이상이라면 true
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};