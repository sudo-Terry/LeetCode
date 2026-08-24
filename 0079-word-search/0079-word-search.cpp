#define MAX 10

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[MAX][MAX];
bool flag = false;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        memset(visited, false, sizeof(visited));
        flag = false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] || flag) {
                    visited[i][j] = true;
                    dfs(i, j, board, word, 1);
                    visited[i][j] = false;
                }
            }    
        }

        return flag;
    }

    void dfs(int y, int x, vector<vector<char>>& board, string word, int idx){
        if(flag) return;
        if(idx == word.size()){
            flag = true;
            return;
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if( ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) continue;

            if(!visited[ny][nx] && board[ny][nx] == word[idx]){
                visited[ny][nx] = true;
                dfs(ny, nx, board, word, idx + 1);
                visited[ny][nx] = false;
            }
        }
    }
};