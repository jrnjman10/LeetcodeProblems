class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool unique = true;
        unordered_map<int,int> occurences;
        for(auto i : arr){
            if(occurences.count(i)){
                occurences[i] = occurences[i] + 1;
            } else {
                occurences.emplace(i,1);
            }
        }
        unordered_set<int> occurenceNumbers;
        for(auto i : occurences){
            if (occurenceNumbers.count(i.second)){
                return false;
            } else {
                occurenceNumbers.emplace(i.second);
            }
        }

        return unique;
    }
};