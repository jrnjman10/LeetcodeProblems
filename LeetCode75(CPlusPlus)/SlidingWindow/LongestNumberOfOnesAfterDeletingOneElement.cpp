class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int begin = 0;
    int end = 0;
    int curMax = 0;
    int max = 0;
    int numZeros = 0;
    while(numZeros < 1 && end < nums.size()){
        if(nums[end] == 0){
            numZeros++;
        }
        end++;
    }
    max = end - begin-1;
    curMax = max;
    while(end < nums.size()){
        if(nums[end] == 0){
            numZeros++;
        }
        while(numZeros > 1){
            if(nums[begin] == 0){
                numZeros--;
            }
            begin++;
        }
        curMax = end - begin;
        if(curMax > max){
            max = curMax;
        }
        end++;
    }
    return max;

    }
};