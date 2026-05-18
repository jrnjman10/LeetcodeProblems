class Solution {
public:
    string removeStars(string s) {
        string stack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                stack.pop_back();
            } else {
                stack += s[i];
            }
        }
        return stack;
    }
};