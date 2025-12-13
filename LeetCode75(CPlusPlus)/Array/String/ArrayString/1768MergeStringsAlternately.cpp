#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mixedString = "";
    string mergeAlternately(string word1, string word2) {
        int longestLength = max(word1.length(),word2.length());
        for(int i = 1; i <= longestLength; i++){
            //check if i is going past the word's length
            if(i <= word1.length()){
                    mixedString = mixedString + word1[i-1];
            }
            if(i <= word2.length()){
                mixedString = mixedString + word2[i-1];
            }
            
        }
        return mixedString;      
    }
};