class Solution {
public:
    bool closeStrings(string word1, string word2) {
        /*
        Go char by char on each string
        as long as they have the same chars and same length the strings are close
        */

        //hash set
        //unordered_set
        unordered_set<char> existChar;
        if(word1.length() == word2.length()){
            //while not at end of string
            auto i = word1.begin();
            while(i != word1.end()){
                //if char not in unordered set emplace
                if(existChar.find(*i) == existChar.end()){
                    existChar.emplace(*i);
                }
                //iterate over chars
                //cout << *i << " \n";
                i++;
            }

            auto j = word2.begin();
            //while not at end of string2
            while(j != word2.end()){
                //if char not in unordered set return false
                //cout << *j << " \n";
                if(existChar.find(*j) == existChar.end()){
                    return false;
                }
                //iterate over chars
                j++;
            }
            return true;
        } else {
            return false;
        }
    }
};