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

/*

//Second Naive solution: I think now I'm just going to try to do some sort of swapping
//I think just swapping chars in the string and then stopping swapping when the iterators meet

class Solution {
public:
    string reverseVowels(string s) {
        string final = "";
        auto forwardIterator = s.begin();
        auto backwardIterator = s.end();
        bool foundVowl = false;
        while (forwardIterator != s.end()){
            for (auto j : "aeiouAEIOU"){
                if(*forwardIterator == j){
                    foundVowl = true;
                }
            }

            if(foundVowl){
                while(backwardIterator >= s.begin() && foundVowl){
                    backwardIterator--;
                    for( auto j : "aeiouAEIOU"){
                        if (*backwardIterator == j){
                            foundVowl = false;
                            final = final + *backwardIterator;
                        }
                    }
                    }
            } else {
                final = final + *forwardIterator;
            }
            //cout << "\n" << *forwardIterator << " " << *backwardIterator;
            forwardIterator++;
        }
        return final;
    }
};
*/



class Solution {
public:
    string reverseVowels(string s) {
        auto forwardIterator = s.begin();
        auto backwardIterator = s.end();
        char placeholder;
        bool foundVowl = false;
        bool findSwap = false;
        while (forwardIterator < backwardIterator){
            for( auto i : "aeiouAEIOU"){
                if(*forwardIterator == i) foundVowl = true;
            }
            while(foundVowl && backwardIterator >= forwardIterator){
                backwardIterator--;
                //cout << *backwardIterator << "\n";
                for (auto i : "aeiouAEIOU"){
                    if(*backwardIterator == i){
                        foundVowl = false;
                        findSwap = true;
                    }
                }
            }
            if(findSwap){
                findSwap = false;
                //cout << *forwardIterator << " swaps with " << *backwardIterator << "\n";
                placeholder = *forwardIterator;
                *forwardIterator = *backwardIterator;
                *backwardIterator = placeholder;
            }
            forwardIterator++;
        }
        return s;
    }
};