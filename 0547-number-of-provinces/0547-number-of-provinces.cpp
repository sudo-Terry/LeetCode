#define MAX 210

class Solution {
    queue<int> q;
    bool visited[MAX];
    int n;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(visited, false, sizeof(visited));
        n = isConnected.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                q.push(i);
                visited[i];
                ans++;
                bfs(isConnected);
            }
        }

        return ans;
    }

private:
    void bfs(vector<vector<int>>& isConnected){
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < n; i ++){
                if(visited[i]) continue;

                if(isConnected[curr][i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};