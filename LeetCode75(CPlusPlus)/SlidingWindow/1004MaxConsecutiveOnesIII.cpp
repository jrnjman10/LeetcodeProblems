class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto it1 = nums.begin();
        auto it2 = nums.begin();
        int max1 = 0;
        int curMax = 0;
        int zerosLeft = k;
        while(zerosLeft > 0 && it2 < nums.end()){
            cout << to_string(*it2) << " ";
            if(*it2 == 0){
                zerosLeft--;
            }
            it2++;
            curMax++;
        }
        cout << "\n";
        max1 = curMax;
        while(it2 < nums.end()){
            if(*it2 == 1){
                curMax++;
                it2++;
            } else if (*it2 == 0 && zerosLeft > 0){
                curMax++;
                zerosLeft--;
                it2++;
            } else if (k == 0) {
                it2++;
                it1 = it2;
                curMax = 0;
            } else {
                if(*it1 == 1){
                    it1++;
                    curMax--;
                } else {
                    it1++;
                    curMax--;
                    zerosLeft++;
                }
            }

            if(curMax > max1){
                max1 = curMax;
            }
        }

        return max1;
        
    }
};