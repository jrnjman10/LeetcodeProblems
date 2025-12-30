#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         auto hunt = nums.begin()+1;
//         auto start = nums.begin();
//         int index = 0;   
//         int count = 0;  
//         auto print = nums.begin();   
//         print = nums.begin();
//         // while(print < nums.end()){
//         //     cout << to_string(*print) << " ";
//         //     print++;
//         // }
//         // cout << "\n";
//         while(start < nums.end()){
//             // while(*start > k && start < nums.end()){
//             //     start++;
//             //     hunt++;
//             //     index++;
//             // }
//             while(hunt < nums.end() && start < nums.end()-1){
//                 // cout << to_string(*start) << " start " << to_string(*hunt) << " hunt\n";
//                 // print = nums.begin();
//                 // while(print < nums.end()){
//                 //     cout << to_string(*print) << " ";
//                 //     print++;
//                 // }
//                 // cout << "\n";
//                 // if(*start == 1 || *start == 2){
//                 //     cout << to_string(*start) << " start " << to_string(*hunt) << " hunt\n";
//                 // }
//                 if((*start)+(*hunt) == k){
//                     count++;
//                     /*BIG LESSON HERE
//                         THE ORDER MATTERS OF ERASING
//                         HUNT WAS EFFECTED BY START'S ERASURE
//                      */
//                     nums.erase(hunt);
//                     nums.erase(start);
//                     if(index != 0){
//                         index--;
//                     }
//                     start = nums.begin()+index;
//                     hunt = nums.begin()+index+1;
//                     // print = nums.begin();
//                     // while(print < nums.end()){
//                     //     cout << to_string(*print) << " ";
//                     //     print++;
//                     // }
//                     // cout << "\n";
//                 } else if(hunt < nums.end()){
//                     hunt++;
//                 }
//             }
//             // print = nums.begin();
//             // while(print < nums.end()){
//             //     cout << to_string(*print) << " ";
//             //     print++;
//             // }
//             // cout << "\n";
//             if(start < nums.end()){
//                 start = nums.begin()+index;
//                 hunt = nums.begin()+index+1;
//                 index++;
//             }
//             // if(start != nums.end()){
//             //     cout << to_string(*start) << " start\n";
//             // }
//         }
//         return count;
//     }
// };
void heapify(vector<int>& nums, int size, int rIndex);


// while(heapCount > 0){
        //     //heapify
        //     //swap last index with first index
        // }

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int root = 0;
        int n = nums.size();
        
        for(int i = n/2 -1; i >= 0; i--){
            heapify(nums,n,i);
        }
        
        auto it = nums.begin();
        while(n > 0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
        //list is sorted
        auto beginIt = nums.begin();
        auto endIt = nums.end()-1;
        int count = 0;
        while(beginIt < endIt){
            if(*beginIt + *endIt == k){
                beginIt++;
                endIt--;
                count++;
            } else if(k - *endIt > *beginIt){
                beginIt++;
            } else {
                endIt--;
            }
        }
        return count;
    }
};

void heapify(vector<int>& nums, int size, int rIndex){
    int largest = rIndex;

    int l = rIndex * 2 + 1;
    int r = rIndex * 2 + 2;

    if(l < size && nums[l] > nums[largest]){
        largest = l;
    }

    if(r < size && nums[r] > nums[largest]){
        largest = r;
    }

    if(largest != rIndex){
        swap(nums[rIndex],nums[largest]);    
        heapify(nums, size, largest);
    }
}



int main(){
    Solution l;
    int k = 43;
    vector<int> p = {1,2,3,4};
    cout << to_string(l.maxOperations(p,k));
    return 0;
}