#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //so I need to figure out what the max is in the vector
        //then return a boolean array say that if I add the int ExtraCandies 
        //to the numbers 
        vector<bool> ans;
        int maxValue = candies[0];
        for (int i : candies){
            if(i > maxValue) maxValue = i;
        }

        for (int i : candies){
            if(i+extraCandies >= maxValue){
                ans.push_back(true);
            } else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};