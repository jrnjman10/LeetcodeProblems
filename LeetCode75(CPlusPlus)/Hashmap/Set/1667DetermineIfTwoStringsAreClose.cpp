class Solution {
public:
    bool closeStrings(string word1, string word2) {
        /*
        Go char by char on each string
        as long as they have the same chars and same length the strings are close
        */

        //hash set
        //unordered_set
        unordered_set<char> existChar1;
        unordered_set<char> existChar2;
        if(word1.length() == word2.length()){
            //while not at end of string
            auto i = word1.begin();
            while(i != word1.end()){
                //if char not in unordered set emplace
                if(existChar1.find(*i) == existChar1.end()){
                    existChar1.emplace(*i);
                }
                //iterate over chars
                //cout << *i << " \n";
                i++;
            }

            auto j = word2.begin();
            //while not at end of string2
            while(j != word2.end()){
                //if char not in unordered set emplace
                if(existChar2.find(*j) == existChar2.end()){
                    existChar2.emplace(*j);
                }
                //iterate over chars
                //cout << *i << " \n";
                j++;
            }
            auto k = existChar1.begin();
            while(k != existChar1.end()){
                if(existChar2.find(*k) == existChar2.end()){
                    return false;
                }
                k++;
            }
            auto w = existChar2.begin();
            while(w != existChar2.end()){
                if(existChar1.find(*w) == existChar1.end()){
                    return false;
                }
                w++;
            }
            return true;
        } else {
            return false;
        }
    }
};