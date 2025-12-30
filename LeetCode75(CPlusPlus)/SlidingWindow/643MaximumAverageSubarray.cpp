

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto it = nums.begin();
        double sum;
        double cSum;
        int i = 0;
        for(i; i<k ; i++){
            sum = sum + *it;
            it++;
        }
        auto bIt = nums.begin();
        cSum = sum;
        while(it < nums.end()){
            cSum = cSum - *bIt;
            cSum = cSum + *it;
            if(sum < cSum){
                sum = cSum;
            }
            it++;
            bIt++;
        }
        return sum / k;

    }
};