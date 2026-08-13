class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> keys = rooms[0];
        //maybe something with set or hash table
        //also think of queue here
        /*
        We want to keep track of the places we have visited say ex we visit 3 and another 
        room has the 3 key, we don't want to revisit

        We could use a set to store the places we've been
        We check the set for num, if not in set we can add it to our queue
        and add the number to the set.
        that way it'll be in our set and queue we won't accidently add something to the queue twice
        */

        queue<int> visitingRooms;
        visitingRooms.push(0);
        unordered_set<int> visitedRooms {0};
        //need to think of conditions that I can wrap this in for starting and ending 
        //when the queue is empty we end

        while(!visitingRooms.empty()){
            int curRoom = visitingRooms.front();
            for(int i : rooms[curRoom]){
                if(visitedRooms.count(i) == 0){
                    visitingRooms.push(i);
                    visitedRooms.insert(i);
                }
            }
            visitingRooms.pop();
        }
        return visitedRooms.size() == rooms.size();
        //if the size of the set is smaller than the size of the initial vector than 
        //we didn't reach all of them
    }
};