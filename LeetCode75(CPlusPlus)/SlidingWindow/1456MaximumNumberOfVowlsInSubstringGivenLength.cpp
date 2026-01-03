class Solution {
public:
    int maxVowels(string s, int k) {
        auto it = s.begin();
        int curMax = 0;
        int max;
        for(int i = 0; i < k; i++){
            for(char j : "aeiou"){
                if(j == s[i]){
                    curMax++;
                }
            }
        }
        max = curMax;
        for(int t = k; t < s.size(); t++){
            if(curMax == k){
                return curMax;
            } 
            cout << s[t] << " ";
            for(char j : "aeiou"){
                if(s[t] == j){
                    curMax++;
                } 
            }
            for(char j : "aeiou"){
                if(s[t-k] == j){
                    curMax--;
                }
            }
            if(curMax > max){
                max = curMax;
            }
        }
        return max;
    }
};