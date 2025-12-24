#include <string>

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto itS = s.begin();
        auto itT = t.begin();
        while(itS < s.end() && itT < t.end()){
            if(*itT == *itS){
                itS++;
            }
            itT++;
        }
        return (itS == s.end());
    }
};