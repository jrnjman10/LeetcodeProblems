class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a,b;
        vector<int> distinct1, distinct2;

        for(int i = 0; i < nums1.size(); i++){
            a.insert(nums1[i]);
        }

        for(int i = 0; i < nums2.size(); i++){
            b.insert(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            if(b.find(nums1[i]) != b.end()){
                b.erase(nums1[i]);
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            if(a.find(nums2[i]) != a.end()){
                a.erase(nums2[i]);
            }
        }

        for(int i : a){
            distinct1.emplace_back(i);
        }
        
        for(int i : b){
            distinct2.emplace_back(i);
        }

        vector<vector<int>> final;
        final.emplace_back(distinct1);
        final.emplace_back(distinct2);

        return final;
    }
};