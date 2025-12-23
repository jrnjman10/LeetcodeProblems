class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //bump will start and slowly move along the list until
        //we reach the end of the numbers
        auto itbump = nums.begin();
        auto it1 = itbump;
        auto itnums = nums.begin();
        auto it2 = itnums;
        auto itend = nums.end()-1;
        while(*itend == 0 && itend > nums.begin()){
            itend--;
        }
        while(itbump < itend && itbump < itend){
            while(*itnums == 0 && itnums < itend){
                itnums++;
            }
            swap(*itbump,*itnums);
            itbump++;
            if(itbump > itnums){
                itnums = itbump;
            }
        }
    }
};