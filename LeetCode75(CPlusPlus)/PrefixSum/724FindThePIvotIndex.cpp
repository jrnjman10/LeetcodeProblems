class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int Lsum = 0;
        int Rsum = 0;
        for(int i = 0; i < nums.size(); i++){
            Rsum = Rsum + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            Rsum = Rsum - nums[i];
            if(Rsum == Lsum){
                return i;
            }
            Lsum = Lsum + nums[i];
        }
        return pivot;
    }
};