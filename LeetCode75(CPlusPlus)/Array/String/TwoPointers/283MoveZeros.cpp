class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto iterPlaceholder = nums.begin();
        auto iterBegin = nums.begin();
        auto iterEnd = nums.end()-1;
        while(iterBegin < nums.end()){
            iterPlaceholder = iterBegin;
            while(*iterEnd == 0 && iterEnd > nums.begin()){
                iterEnd--;
            }
            while(*iterBegin == 0 && iterBegin < iterEnd){
                swap(*iterBegin,*(iterBegin+1));
                iterBegin++;
            }
            iterBegin = iterPlaceholder;
            iterBegin++;
        }
    }
};