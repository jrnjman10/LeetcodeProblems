#include <string>
#include <iostream>

using namespace std;

bool stringIn(string base, string seg);

class Solution {
public:
    //.find()
    //.substr(index,length)
    string gcdOfStrings(string str1, string str2) {
        string stringSeg = "";
        int inc;
        if(str1.length() < str2.length()){
            stringSeg = str1;
            inc = stringSeg.length();
        }else{
            stringSeg = str2;
            inc = stringSeg.length();
        }
        //just go down : p
        bool done = false;
        while(done == false){
            if(stringIn(str1,stringSeg) && stringIn(str2,stringSeg)){ 
                break;
            }
            //cout << stringSeg << "yer\n";
            inc = inc - 1;
            stringSeg = stringSeg.substr(0,inc);
            if(stringSeg == "") done = true;
        }
        return stringSeg;
    }
};

bool stringIn(string base, string seg){
    bool ans = false;
    int index = 0;
    while(index < base.length()){
        if(base.substr(index,seg.length()) == seg){
            ans = true;
        } else {
            ans = false;
            return ans;
        }
        //cout << seg << "\n";
        //cout << index << "\n";
        index = index + seg.length();
    }
    return ans;
}