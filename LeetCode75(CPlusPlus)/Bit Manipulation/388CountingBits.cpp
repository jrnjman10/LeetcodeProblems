class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> final(n+1);
        if(n == 0){
            return final;
        }

/*
Powers of 2 are 1
you reflect the previous steps to get to the next
*/

        for(int i = 1; i <= n; i++){
            final[i] = final[i/2] + i%2;
        }      
        return final;
    }
};