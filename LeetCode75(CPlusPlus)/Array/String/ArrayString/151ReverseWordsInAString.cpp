// class Solution {
// public:
//     string reverseWords(string s) {
//         //maybe usages of substr
//         //swap
//         //npos
//         auto startIterPos1 = s.begin();
//         auto startIterPos2 = s.begin();
//         auto endIterPos1 = s.end()-1;
//         auto endIterPos2 = s.end()-1;
//         string::iterator placeholder;
//         int wordCount;

//         //white space removal
//         while(*startIterPos2 == ' '){
//             startIterPos2++;
//         }

//         while(startIterPos2 <= endIterPos2){
//             while(*startIterPos2 != ' ' && startIterPos2 != endIterPos2){
//                 swap(*startIterPos2, *startIterPos1);
//                 //cout << *startIterPos2 << " " << *startIterPos1 << "\n";
//                 startIterPos1++;
//                 startIterPos2++;
//             }
//             startIterPos2++;
//             startIterPos1++;
//             while(*startIterPos2 == ' '){
//                 startIterPos2++;
//             }   
//             //startIterPos1 = startIterPos2;
//         }

//         while(*endIterPos2 == ' '){
//             s.pop_back();
//             endIterPos2--;
//         }

//         endIterPos1 = endIterPos2;

//         startIterPos1 = s.begin();
//         startIterPos2 = s.begin();
//         //end of white space removal

//         //will have to check that != for > < >= <= 
//         while(startIterPos2 <= endIterPos1){
//             //the first swap is the two end words
//             // then it's two interior words
//             // ... word3 ... ... word5 ...
//             //I'm thinking I want something that'll act like a stack
//             //To just go into a final string, but that could show some challenges
//             if(*startIterPos2 != ' '){
//                 startIterPos2++;
//             }
//             if(*endIterPos1 != ' '){
//                 endIterPos1--;
//             }

//             //need to think about how I need to place the first position word correctly
//             //might want to think about what I can do with the ends of the words
//             //I could swap what would be at the tail end of the word to the start
//             //of a word and make sure that only the begining of the words are swapped
//             //and the remainder of any word is in the proper order.
//             if(*startIterPos2 == ' ' && *endIterPos1 == ' '){
//                 cout << s << "\n";
//                 if (startIterPos2 - startIterPos1 == endIterPos2 - endIterPos1){
//                     cout << "the same\n";
//                     placeholder = endIterPos1;
//                     endIterPos1 = endIterPos1+1;
//                     // while(endIterPos1 < endIterPos2){
//                     //     swap(*endIterPos1, *(endIterPos1+1));
//                     //     endIterPos1++;
//                     //     cout << s << "\n";
//                     // }
//                     endIterPos1 = placeholder;

//                     placeholder = endIterPos1;
//                     endIterPos1++;
//                     while(endIterPos1 <= endIterPos2){
//                         swap(*endIterPos1,*startIterPos1);
//                         cout << s << "\n";
//                         endIterPos1++;
//                         startIterPos1++;
//                     }
//                     endIterPos1 = placeholder;

//                     while(*endIterPos1 == ' '){
//                         endIterPos1--;
//                     }
//                     endIterPos2 = endIterPos1;
//                 } else if(startIterPos2 - startIterPos1 >= endIterPos2 - endIterPos1){
//                     cout << "first word is bigger\n";
//                     int difference = (startIterPos2 - startIterPos1) - (endIterPos2 - endIterPos1);
//                     cout << difference << "\n";
//                     //Trygve Jill Mack Joe
//                     //right side MackJoe_
//                     //ie Joe_
//                     placeholder = startIterPos2;
//                     while(startIterPos1 < startIterPos2){
//                         swap(*startIterPos2, *(startIterPos2-1));
//                         startIterPos2--;
//                         cout << s << "\n";
//                     }
//                     startIterPos2 = placeholder;
//                     FullWordSwapper(endIterPos1,(endIterPos1-endIterPos2));
//                     //LeftSide ygveTr_ 
//                     PartialWordSwapper(startIterPos1, (startIterPos1 - startIterPos2));
//                     placeholder = endIterPos1;
//                     //has to do with this position
                    
//                     cout << *endIterPos1 << " end1 " << *startIterPos1 << " start1\n";
//                     while(endIterPos1 <= endIterPos2){
//                         swap(*endIterPos1,*startIterPos1);
//                         cout << s << "\n";
//                         endIterPos1++;
//                         startIterPos1++;
//                     }
//                     //we don't place hold for the start because we want to retain those swaps
//                     endIterPos1 = placeholder;

//                     //get to the start of the next word
//                     while(*endIterPos1 == ' '){
//                         endIterPos1--;
//                     }
//                     endIterPos2 = endIterPos1;

//                 } else {
//                     cout << "second word is bigger\n";
//                     //where first letter needs to go

//                      //Joe Jill Mack Trygve
//                     //Left side Joe_
//                     //ie _Joe
//                     placeholder = startIterPos2;
//                     while(startIterPos2 > startIterPos1){
//                         swap(*startIterPos2, *(startIterPos2-1));
//                         cout <<  s << "\n";
//                         startIterPos2--;
//                     }
//                     startIterPos2 = placeholder;
//                     FullWordSwapper(startIterPos1, (startIterPos1 - startIterPos2));
//                     //Rightside ygveTr_ 
//                     PartialWordSwapper(endIterPos1,(endIterPos1-endIterPos2));
//                     placeholder = endIterPos1;
//                     //it'll matter here too when we need to make sure there is enough 
//                     //room for the word
//                     endIterPos1++;
//                     while(startIterPos1 < startIterPos2){
//                         swap(*endIterPos1, *startIterPos1);
//                         cout << s << "\n";
//                         endIterPos1++;
//                         startIterPos1++;
//                     }
//                     endIterPos1 = placeholder-1;
//                     endIterPos2 = endIterPos1;
//                     // while(*startIterPos2 == ' '){
//                     //     startIterPos2++;
//                     // }
//                     startIterPos1++;
//                     startIterPos2 = startIterPos1;
//                     cout << *startIterPos1 << " start1 " << *endIterPos1 << " end1\n";
//                 }
//                 //commence swap
//                 //hand the 2 cases when the words are not equal in length
//             }
//         }
//         return s;
//     }
//     void FullWordSwapper(string::iterator s1, int s1Length){
//         //check for number of complete words (i.e spaces)
//         //cycle to setup
        
//     }
//     void PartialWordSwapper(string::iterator s1, int s1Length){

//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        //maybe usages of substr
        //swap
        //npos
        auto startIterPos1 = s.begin();
        auto startIterPos2 = s.begin();
        auto endIterPos1 = s.end()-1;
        auto endIterPos2 = s.end()-1;
        string::iterator placeholder;
        int wordCount;

        //white space removal
        while(*startIterPos2 == ' '){
            startIterPos2++;
        }

        while(startIterPos2 <= endIterPos2){
            while(*startIterPos2 != ' ' && startIterPos2 <= endIterPos2){
                swap(*startIterPos2, *startIterPos1);
                startIterPos1++;
                startIterPos2++;
            }
            startIterPos2++;
            startIterPos1++;
            while(startIterPos2 < endIterPos2 && *startIterPos2 == ' '){
                startIterPos2++;
            } 
        }

        while(*endIterPos2 == ' '){
            s.pop_back();
            endIterPos2--;
        }

        cout << s << "\n";

        endIterPos1 = endIterPos2;

        startIterPos1 = s.begin();
        startIterPos2 = s.begin();
        while(startIterPos2 <= endIterPos1){
            if(*startIterPos2 != ' '){
                startIterPos2++;
            }
            if(*endIterPos1 != ' '){
                endIterPos1--;
            }
                    //Trygve Jill Mack Joe
                    //right side MackJoe_
                    //ie Joe_
                    //LeftSide ygveTr_ 
            if(*startIterPos2 == ' ' && *endIterPos1 == ' '){
                break;
            }
        }
        return s;
    }
    void FullWordSwapper(string::iterator s1, int s1Length){
        //check for number of complete words (i.e spaces)
        //cycle to setup
        
    }
    void PartialWordSwapper(string::iterator s1, int s1Length){

    }
};