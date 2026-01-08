class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev = gain[0];
        int i = 1;
        int max = 0;
        if(gain[0] > 0){
            max = gain[0];
        }
        while(i < gain.size()){
            prev = prev + gain[i];
            if(prev > max){
                max = prev;
            }
            i++;
        }
        return max;
    }
};