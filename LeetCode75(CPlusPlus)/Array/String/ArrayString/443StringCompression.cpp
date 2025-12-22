// 


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