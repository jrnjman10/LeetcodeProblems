class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> final;
        if(n == 0){
            final.push_back(1);
            return final;
        }


        final.push_back(0);
        for(int i = 1; i <= n; i++){
            int sum = 0;
            int num = i;
            while(num != 0){
                sum += num%2;
                num = num/2;
            }
            final.push_back(sum);
        }      
        return final;
    }
};