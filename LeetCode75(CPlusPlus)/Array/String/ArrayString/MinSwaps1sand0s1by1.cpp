
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;



template<typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& v){
    for(const auto& i : v){
        os << i << " ";
    }
    return os;
}

class Solution{
public:

    int minSwaps(vector<int> arr){
        int n = arr.size();
        int swaps = 0;
        if(n < 2){
            return swaps;
        }
        int curr = 0;
        int back = n-1;
        while(curr < back){
            //cout << arr << " " << curr << " " << back << "\n";
            //cout << curr << "\n";
            if(arr[curr] == 0){
                curr++;
            } else if (arr[back] == 1){
                back -= 1;
            } else {
                int placeholder = curr;
                //cout << curr << " " << back << "\n";
                for(int i = curr; curr < back; curr++){
                    swaps++;
                    int o = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = o;
                }
                curr = placeholder;
                curr++;
            }
        }
        return swaps;
    }
};


int main(){

    std::vector<int> a{0,0,0,1,0,1,1,1};
    vector<int> b{1,0,0,0,0,1,1,1,1};
    Solution sol;
    if(1 == sol.minSwaps(a)){
        cout << "Test 1 passed\n";
    }
    if(4 == sol.minSwaps(b)){
        cout << "Test 2 passed\n";
    }
    return 0;
}