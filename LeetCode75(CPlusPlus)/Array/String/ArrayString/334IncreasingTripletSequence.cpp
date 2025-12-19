class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool final = false;
        if(nums.size() < 2){
            return final;
        }
        auto iter = nums.begin();
        int p1 = pow(2,31) - 1;
        int p2 = pow(2,31) - 1;
        int p3;
        while(iter < nums.end()){
            if(*iter <= p1){
                p1 = *iter;
            } else if(*iter <= p2) {
                p2 = *iter;
            }
            if (*iter > p2 && p2 > p1){
                p3 = *iter;
                final = true;
                break;
            }
            iter++;
        }
        cout << p1 << " p1 " << p2 << " p2 " << p3 << " p3\n";
        return final;
    }
};