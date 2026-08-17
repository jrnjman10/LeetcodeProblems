class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        /*
            Just check up, right, down, left
            if clear add position to queue
        */

        int sizeL = maze.size(); //
        int sizeW = maze[0].size()-1; //gives us coords to check if valid

        queue<vector<int>> q;
        q.push(entrance);
        int steps = -1;
        //we don't check if entrance is exit
        vector<int> curr;
        bool escaped = false;
        while(!escaped){
            curr = q.front();
            int x = curr[1];
            int y = curr[0];
            vector<int> add;
            steps++;
            if(curr[0] == 0 || curr[0] == sizeL || curr[1] == 0 || curr[1] == sizeW && curr != entrance) escaped = true;
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
            q.pop();
        }


        if (!escaped) return -1;
        return steps;
    }
};