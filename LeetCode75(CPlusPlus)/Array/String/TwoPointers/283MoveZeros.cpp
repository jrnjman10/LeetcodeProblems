class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto iterBegin = nums.begin();
        auto iterEnd = nums.end()-1;
        while(iterBegin <= iterEnd){
            if(*iterBegin == 0){
                swap(*iterBegin, *iterEnd);
                iterEnd--;
            }
            iterBegin++;
        }
    }
};