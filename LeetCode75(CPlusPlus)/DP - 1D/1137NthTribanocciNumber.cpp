ostream& operator<<(ostream& os, vector<int> v){
    for(auto i : v){
        os << i << " ";
    }
    return os;
}

class Solution {
public:

    void recursion(vector<int>& prev, int i, int end){
        if(i < 3){
            recursion(prev,i+1,end);
        } else if (i <= end){
            int k = prev[i-1] + prev[i-2] + prev[i-3];
            prev.push_back(k);
            recursion(prev,i+1,end);
        }
        return;
    }


    int tribonacci(int n) {
        vector<int> prev = {0,1,1};
        recursion(prev,0,n);
        return prev[n];
    }
};