#define MAX 10
bool visited[MAX];

class Solution {
private:
    void backtrack(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr.push_back(nums[i]);
                
                backtrack(nums, ans, curr);
                
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        memset(visited, false, sizeof(visited));
        
        backtrack(nums, ans, curr);

        return ans;
    }
};