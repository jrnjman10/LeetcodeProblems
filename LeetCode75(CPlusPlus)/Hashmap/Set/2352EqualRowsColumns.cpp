class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        //For each row, I need to compare each column
        //to cleanly index rows I just need to index the grid i.e. grid[0] returns first row and so on
        //to index colums I need to go to the length of grid, and iterate taking the number at the same index from each array i.e.
        //take grid[0][0], grid[1][0] ... grid [n][0]
        //we can quit searching when something doesn't align
        //so in a 3x3 first session for row we have grid[0][0], grid[0][1], and grid[0][2].
        //then column is grid[0][0] grid[1][0] grid[2][0]
        //The simple solution I am finding right now is n^2.
        //compare each row with each column
        //let's do that first
        int count = 0;
        //will check if the comparisons ever reach the end, if so count will go + 1
        int currCount;
        for(auto i = 0; i < grid.size(); i++){
            for(auto i2 = 0; i2 < grid.size(); i2++){
                //we have the current array at grid[i]
                //i2 is the current x value
                //c will be the y value
                currCount = 0; //reset the currCount
                for(auto c = 0; c < grid.size(); c++){
                    //grid[c][i2], grid[c+1][i2], and grid[c+2][i2] ...
                    //versus the indexs of grid[i][c], grid[i][c+1], grid[i][c+2]
                    cout << grid[c][i2] << " " << grid[i][c] << "\n";
                    if(grid[c][i2] != grid[i][c]){
                        cout << "break";
                        break; //break changes the column here, it'll stop iterating the current culumn, the above i2 will move to the next column over
                    }
                    currCount++;
                }
                //did the column and row match?
                //if it made it all the way to the end they match
                if(currCount == grid.size()){
                    count++;
                }
            }
        }
        return count;
    }
};


/*
For the faster solution you store the rows as a map
Then you interate by columns and compare the created column, to see if it is in the map
If it is you iterate if not, then don't
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        map<vector<int>,int> mp;
        for(auto i = 0; i < grid.size(); i++){
            mp[grid[i]]++;
        }
        int counter = 0;
        vector<int> v;

        for(auto i = 0; i < grid.size(); i++){
            //column we need grid[c][0], c+1 0, c+2 0, ...
            
            for(auto c = 0; c < grid.size(); c++){
                v.emplace_back(grid[c][i]);
                // cout << grid[c][i] << " " << grid[i][c] << "\n";
            }
            auto it = mp.find(v);
            if(it != mp.end()){
                counter += it->second;
            }

            v.clear();
            // cout << "--------------------\n";
        }
        return counter;
    }
};
