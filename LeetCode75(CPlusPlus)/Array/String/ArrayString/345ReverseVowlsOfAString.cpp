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
    int compress(vector<char>& chars) {
        auto iterOri = chars.begin();
        auto iterNew = chars.begin();
        char curChar = *iterOri;
        int count = 0;
        while(iterNew != chars.end()){
            // for(auto j : chars){
            //     cout << j;

            // }
            //cout << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
            if(*iterNew != curChar){
                if(count != 1){
                //erase the elements from 
                //origin to New
                //InsertNumber if count > 1
                //count = 1
                //iterOri = iterNew
                //insert happens before the iterator
                //erase is [ )
                //set curChar
                    chars.erase(iterOri+1,iterNew);
                    for(auto j : chars){
                        cout << j;
                    }
                    cout << "\n";
                    //cout << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
                    for(auto i : to_string(count)){
                        chars.insert(iterNew-1,i);
                    }   
                    for(auto j : chars){
                        cout << j;
                    }
                    cout << "\n";
                    //cout << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
                } 
                curChar = *iterNew;
                iterOri = iterNew;
                count = 1;
            } else {
                count++;
                //cout << to_string(count) << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
            }
            iterNew++;
        }
        if(count != 1){
            chars.erase(iterOri+1,iterNew);
            for(auto i : to_string(count)){
                        //cout << i << "\n";
                        chars.insert(chars.begin()+chars.size(),i);
            } 
        }
        return chars.size();
    }
};