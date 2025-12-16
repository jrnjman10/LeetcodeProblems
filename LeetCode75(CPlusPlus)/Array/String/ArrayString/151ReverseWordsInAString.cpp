class Solution {
public:
    string reverseWords(string s) {
        //maybe usages of substr
        //swap
        //npos
        //with replace I just keep track of where I strated and where I'm at
        //Then what I replace with is the current strings
        auto startIterPos1 = s.begin();
        auto startIterPos2 = s.begin();

        //Pos 1 will be leftmost value and Pos 3 the rightmost

        auto endIterPos1 = s.end()-1;
        auto endIterPos2 = s.end()-1;
        string::iterator placeholder;
        //how do I do it in place


        //will have to check that != for > < >= <= 
        while(startIterPos2 <= endIterPos1){
            //the first swap is the two end words
            // then it's two interior words
            // ... word3 ... ... word5 ...
            //I'm thinking I want something that'll act like a stack
            //To just go into a final string, but that could show some challenges
            if(*startIterPos2 != ' '){
                cout << *startIterPos2;
                startIterPos2++;
            }
            if(*endIterPos1 != ' '){
                cout << *endIterPos1;
                endIterPos1--;
            }

            //need to think about how I need to place the first position word correctly
            //might want to think about what I can do with the ends of the words
            if(*startIterPos2 == ' ' && *endIterPos1 == ' '){
                if(startIterPos2 - startIterPos1 > endIterPos2 - endIterPos1){
                    cout << "\nfirst word is bigger\n";
                    placeholder = endIterPos1;
                    //has to do with this position
                    endIterPos1++;
                    while(endIterPos1 <= endIterPos2){
                        swap(*endIterPos1,*startIterPos1);
                        cout << s << "\n";
                        endIterPos1++;
                        startIterPos1++;
                    }
                    //we don't place hold for the start because we want to retain those swaps
                    endIterPos1 = placeholder;

                    //get to the start of the next word
                    while(*endIterPos1 == ' '){
                        endIterPos1--;
                    }
                    endIterPos2 = endIterPos1;

                } else {
                    cout << "\nsecond word is bigger or same\n";
                    placeholder = endIterPos1;
                    //it'll matter here too when we need to make sure there is enough 
                    //room for the word
                    endIterPos1++;
                    while(startIterPos1 < startIterPos2){
                        swap(*endIterPos1, *startIterPos1);
                        cout << s << "\n";
                        endIterPos1++;
                        startIterPos1++;
                    }
                    endIterPos1 = placeholder;
                    endIterPos2 = endIterPos1;
                    while(*startIterPos2 == ' '){
                        startIterPos2++;
                    }
                    startIterPos1 = startIterPos2;
                }
                //commence swap
                //hand the 2 cases when the words are not equal in length
            }
        }
        return s;
    }
};