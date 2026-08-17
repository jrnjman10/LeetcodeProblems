class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        /*
            Just check up, right, down, left
            if clear add position to queue
        */

        int sizeL = maze.size(); //
        int sizeW = maze[0].size(); //gives us coords to check if valid

        queue<vector<int>> q;
        q.push(entrance);
        int steps = -1;
        //we don't check if entrance is exit
        vector<int> curr;
        bool escaped = false;
        while(!q.empty()){
            curr = q.front();
            int x = curr[1];
            int y = curr[0];
            steps = abs(y-entrance[0]) + abs(x-entrance[1]);
            vector<int> add;
            cout << curr[0] << curr[1] << " " << entrance[0] << entrance [1] << "\n";
            if((curr[0] == 0 || curr[0] == sizeL-1 || curr[1] == 0 || curr[1] == sizeW-1) && (curr[0] != entrance[0] || curr[1] != entrance[1])) return steps;
            //up
            if(y-1 > -1 && maze[y-1][x] != '+'){
                add.push_back(y-1);
                add.push_back(x);
                q.push(add);
                add.clear();
            }
            //down
            if(y+1 < sizeL && maze[y+1][x] != '+'){
                add.push_back(y+1);
                add.push_back(x);
                q.push(add);
                add.clear();
            }
            //right
            if(x-1 > -1 && maze[y][x-1] != '+'){
                add.push_back(y);
                add.push_back(x-1);
                q.push(add);
                add.clear();
            }
            //left
            if(x+1 < sizeW && maze[y][x+1] != '+'){
                add.push_back(y);
                add.push_back(x+1);
                q.push(add);
                add.clear();
            }
            q.pop();
        }


        return -1;
    }
};