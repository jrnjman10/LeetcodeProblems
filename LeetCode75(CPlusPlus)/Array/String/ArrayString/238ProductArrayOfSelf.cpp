class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> final(nums.size(),1);
        int i = 1;
        int j = nums.size()-2;
        int v = nums.size()-1;
        while(i < nums.size()){
            final[i] = nums[i-1] * final[i-1];
            i++;
        }
        while(j >= 0){
            nums[j] = nums[j+1] * nums[j];
            j--;
        }
        while(v >= 1){
            final[v-1] = nums[v] * final[v-1];
            v--;
        }
        return final;
    }
};