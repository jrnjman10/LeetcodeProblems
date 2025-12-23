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
        while(itbump < itend){
            it1 = itbump;
            if(*itbump == 0){
                while(itbump < itend){
                    swap(*itbump,*(itbump+1));
                    itbump++;
                }
                itend--;
                itbump = it1;
            } else {
                itbump++;
            }
        }
    }
};