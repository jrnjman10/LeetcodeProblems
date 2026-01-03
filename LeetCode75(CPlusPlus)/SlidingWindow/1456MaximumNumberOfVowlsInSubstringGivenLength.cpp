bool isVowl(char c);

class Solution {
public:
    int maxVowels(string s, int k) {
        auto it = s.begin();
        int curMax = 0;
        int max;
        for(int i = 0; i < k; i++){
            if(isVowl(s[i])){
                curMax++;
            }
            
        }
        max = curMax;
        for(int t = k; t < s.size(); t++){
            //cout << to_string(curMax) << " ";
            if(curMax == k){
                return curMax;
            } 
            if(curMax != 0 && isVowl(s[t-k])){
                curMax--;
            }
            if(isVowl(s[t])){
                curMax++;
            } 
            if(curMax > max){
                max = curMax;
            }
        }
        return max;
    }
};

bool isVowl(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}