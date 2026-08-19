class Solution {
public:
    void backtrack(string& digits, int curL, string currS, vector<string>& comb, unordered_map<char,string>& dial){
        if(curL == digits.length()){
            comb.push_back(currS);
            return;
        }
        string letter = dial[digits[curL]];
        for(auto i : letter){
            backtrack(digits, curL+1, currS + i, comb, dial);
        }
        
    }


    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.empty()){
            return combinations;
        }
        unordered_map<char,string> dial = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        backtrack(digits,0, "", combinations, dial);
        return combinations;
    }
};