class Solution {
public:
    void dfs(int i, int j,int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(i== -1 || j == -1 || i==m || j ==n || grid[i][j]=='0' || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        dfs(i-1, j, m, n, grid, visited);
        dfs(i+1, j, m, n, grid, visited);
        dfs(i, j-1, m, n, grid, visited);
        dfs(i, j+1, m, n, grid, visited);
    }

    void bfs(int i, int j,int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(x== -1 || y == -1 || x==m || y ==n || grid[x][y]=='0' || visited[x][y]){
                continue;
            }
            visited[x][y] = true;
            for(auto& [dx, dy]: directions){
                int nx = x + dx;
                int ny = y+ dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && !visited[nx][ny]){
                    q.push({nx, ny});
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count =0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i, j,m,n, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};