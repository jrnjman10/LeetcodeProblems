class Solution {
public:

    void recurse(int& m, int& n, int& uniquePaths, int dM, int dN){
        if(dM == m-1 && dN == n-1){
            return;
        }
        
        if(dM < m-1 && dN < n-1){
            uniquePaths = uniquePaths+1;
            recurse(m,n,uniquePaths,dM,dN+1);
            recurse(m,n,uniquePaths,dM+1,dN);
        } else if ( dM < m-1){
            //uniquePaths++;
            recurse(m,n,uniquePaths,dM+1,dN);
        } else {
            //uniquePaths++;
            recurse(m,n,uniquePaths,dM,dN+1);
        }

    }

    int uniquePaths(int m, int n) {
        int dM = 0;
        int dN = 0;
        int uniquePaths = 1;
        recurse(m,n,uniquePaths,dM,dN);
        return uniquePaths;
    }
};