/*

First Naive solution
Problems with memory eventually

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> consanents = {};
        vector<char> vowls = {};
        string vowlList = "aeiouAEIOU";
        bool isVowl = false;
        string final = "";
        for (auto i : s){
            isVowl = false;
            for ( auto j : vowlList){
                if(i == j){
                    isVowl = true;
                }
            }

            if(isVowl){
                vowls.emplace(vowls.begin(),i);
            } else{
                consanents.emplace_back(i);
            }
        }
        auto vCounter = vowls.begin();
        isVowl = false;
        for(auto i : s){
            isVowl = false;
            for ( auto j : vowlList){
                if(i == j){
                    isVowl = true;
                }
            }
            if(isVowl){
                final = final + *vCounter;
                vCounter++;
            } else{
                final = final + i;
            }
        }
        return final;
    }
};
*/