#include <vector>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //size will give me size
        //can cover the edge case of 1 flower bed
        bool final = false;
        int freeSp = 0;
        auto i = flowerbed.begin();
        auto behind = flowerbed.begin();

        //check the first slot
        //advance the pointer to be in second slot

        /*
        My primary concern should be over counting
        if the next two spaces are zeros then go to the 
        end of the 3 and increase count
        */
        int numZeros = 1;
        if (flowerbed.size() == 1){
            if (*i == 0){
                freeSp++;
            }
        } else {
            //numZeros begins at 1 because the
            //space in front of the vector is "empty"
            //every time there is 3 zeros in a row 
            //we will increments the count of free spots
            while (i != flowerbed.end()){
                if(*i == 0){
                    numZeros++;
                } else {
                    numZeros = 0;
                }
                //numZeros is 1 since there still is an adjacent
                //space next to that space
                if(numZeros == 3){
                    freeSp++;
                    numZeros = 1;
                }
                i++;
            }
        }
        //there is and "empty spot" at the end of the thing
        //so we need to increase count of free spots if there
        //were 2 free spots before
        if(numZeros == 2){
            freeSp++;
        }
        if( freeSp >= n){
            final = true;
        }
        return final;

    }
};