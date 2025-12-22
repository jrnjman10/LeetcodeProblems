// #include <string>
// #include <stdio.h>
// #include <vector>
// #include <iostream>

// using namespace std;

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         string s{""};
//         auto iter = chars.begin();
//         char curChar = *iter;
//         int count = 0;
//         while(iter != chars.end()){
//             cout << count << "\n";
//             if(*iter != curChar){
//                 if(count == 1){
//                     s = s + curChar;    
//                 } else {
//                     s = s + curChar + to_string(count);
//                 }
//                 //cout << s << "\n";
//                 curChar = *iter;
//                 count = 1;
//             } else {
//                 count++;
//             }
//             iter++;
//         }
//         s = s + curChar + to_string(count);
//         cout << s << " s \n";

//         return s.size();
//     }
// };


// int main (){
//     Solution F;
//     vector<char> bud;
//     bud.emplace_back('a');
//     bud.emplace_back('a');
//     bud.emplace_back('a');
//     bud.emplace_back('b');
//     bud.emplace_back('b');
//     bud.emplace_back('c');
//     bud.emplace_back('c');
//     bud.emplace_back('c');
//     int me = F.compress(bud);
//     //cout << to_string(me) + "\n";
//     auto iter = bud.begin();
//     // while(iter != bud.end()){
//     //     cout << *iter;
//     //     iter++;
//     // }
//     // cout << "\n";
//     return 0;
// }

class Solution {
public:
    int compress(vector<char>& chars) {
        auto iterOri = chars.begin();
        auto iterNew = chars.begin();
        char curChar = *iterOri;
        int count = 0;
        int charCount = 1;
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
                    // for(auto j : chars){
                    //     cout << j;
                    // }
                    charCount++;
                    iterNew = chars.begin()+charCount;
                    charCount--;
                    //cout << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
                    for(auto i : to_string(count)){
                        chars.insert(chars.begin()+charCount,i);
                        charCount++;
                    }                       
                    // for(auto j : chars){
                    //     cout << j;
                    // }
                    // cout << "\n";
                    //cout << " " << *iterOri << " iterOri " << *iterNew << " iterNew\n";
                } 
                iterNew = chars.begin()+charCount;
                charCount++;
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