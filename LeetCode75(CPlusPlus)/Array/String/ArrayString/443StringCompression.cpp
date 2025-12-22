#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s{""};
        auto iter = chars.begin();
        char curChar = *iter;
        int count = 0;
        while(iter != chars.end()){
            cout << count << "\n";
            if(*iter != curChar){
                if(count == 1){
                    s = s + curChar;    
                } else {
                    s = s + curChar + to_string(count);
                }
                //cout << s << "\n";
                curChar = *iter;
                count = 1;
            } else {
                count++;
            }
            iter++;
        }
        s = s + curChar + to_string(count);
        cout << s << " s \n";

        return s.size();
    }
};


int main (){
    Solution F;
    vector<char> bud;
    bud.emplace_back('a');
    bud.emplace_back('a');
    bud.emplace_back('a');
    bud.emplace_back('b');
    bud.emplace_back('b');
    bud.emplace_back('c');
    bud.emplace_back('c');
    bud.emplace_back('c');
    int me = F.compress(bud);
    //cout << to_string(me) + "\n";
    auto iter = bud.begin();
    // while(iter != bud.end()){
    //     cout << *iter;
    //     iter++;
    // }
    // cout << "\n";
    return 0;
}