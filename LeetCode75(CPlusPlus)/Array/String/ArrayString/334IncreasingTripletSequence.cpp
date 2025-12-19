class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool final = false;
        if(nums.size() < 3){
            return final;
        }
        auto p1 = nums.begin();
        //more benefit middle?
        auto p2 = nums.begin()+1;
        auto p3 = nums.end()-1;
        
        while(p2 < p3){
            //cout << *p1 << " p1 " << *p2 << " p2 " << *p3 << " p3 \n";
            if(*p1 < *p2 && *p2 < *p3){
                final = true; 
            }
            if(*p1 > *p3 && *p2 > *p3){
                p3--;
            }
            //troublesome one
            if(*p2 > *p1 && *p2 > *p3 && *p1 > *p3){
                p3--;
            }
            if(*p2 > *p1 && *p2 > *p3 && *p1 < *p3){
                p2++;
            }
            //seems true that
            if(*p2 < *p3 && *p1 > *p2){
                p1 = p2;
                p2++;
            }
            if(*p1 > *p2 && *p2 > *p3){
                p1 = p2;
                p2++;
                p3--;
            }
            if(final){
                break;
            }
        
        }
        return final;
    }
};