class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        auto hunt = nums.begin()+1;
        auto start = nums.begin();
        int index = 0;   
        int count = 0;  
        auto print = nums.begin();   
        print = nums.begin();
        // while(print < nums.end()){
        //     cout << to_string(*print) << " ";
        //     print++;
        // }
        // cout << "\n";
        while(start < nums.end()){
            // while(*start > k && start < nums.end()){
            //     start++;
            //     hunt++;
            //     index++;
            // }
            while(hunt < nums.end() && start < nums.end()-1){
                // cout << to_string(*start) << " start " << to_string(*hunt) << " hunt\n";
                // print = nums.begin();
                // while(print < nums.end()){
                //     cout << to_string(*print) << " ";
                //     print++;
                // }
                // cout << "\n";
                // if(*start == 1 || *start == 2){
                //     cout << to_string(*start) << " start " << to_string(*hunt) << " hunt\n";
                // }
                if((*start)+(*hunt) == k){
                    count++;
                    /*BIG LESSON HERE
                        THE ORDER MATTERS OF ERASING
                        HUNT WAS EFFECTED BY START'S ERASURE
                     */
                    nums.erase(hunt);
                    nums.erase(start);
                    if(index != 0){
                        index--;
                    }
                    start = nums.begin()+index;
                    hunt = nums.begin()+index+1;
                    // print = nums.begin();
                    // while(print < nums.end()){
                    //     cout << to_string(*print) << " ";
                    //     print++;
                    // }
                    // cout << "\n";
                } else if(hunt < nums.end()){
                    hunt++;
                }
            }
            // print = nums.begin();
            // while(print < nums.end()){
            //     cout << to_string(*print) << " ";
            //     print++;
            // }
            // cout << "\n";
            if(start < nums.end()){
                start = nums.begin()+index;
                hunt = nums.begin()+index+1;
                index++;
            }
            // if(start != nums.end()){
            //     cout << to_string(*start) << " start\n";
            // }
        }
        return count;
    }
};