class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        int r = maze.size();
        int c = maze[0].size();

        vector<vector<bool>> exit(r, vector<bool>(c,false));
        vector<vector<int>> distance(r, vector<int>(c,0));

        for(int i = 0; i < r; i++){
            if(maze[i][0] == '.') exit[i][0] = true;
            if(maze[i][c-1] == '.') exit[i][c-1] = true;
        }
        for(int i = 1; i < c-1; i++){
            if(maze[0][i] == '.') exit[0][i] = true;
        }
        for(int i = 1; i < c-1; i++){
            if(maze[r-1][i] == '.') exit[r-1][i] = true;
        }

        int sx = entrance[0];
        int sy = entrance[1];

        queue<pair<int,int>> q;
        q.push({sx,sy});

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            if(exit[x][y] && (x != sx || y != sy)) return distance[x][y];
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < r && nx >= 0  && ny < c && ny >= 0 && maze[nx][ny] == '.'){
                    if(!distance[nx][ny]){
                        distance[nx][ny] = distance[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};