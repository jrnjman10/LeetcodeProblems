class Solution {
public:
    int maxArea(vector<int>& height) {
        int index1 = 0;
        int index2 = height.size()-1;
        int maxA = min(height[index1],height[index2]) * (index2 - index1);
        while(index1 < index2){
            if(height[index1] < height[index2]){
                index1++;
            } else {
                index2--;
            }
            if(min(height[index1],height[index2]) * (index2 - index1) > maxA){
                maxA = min(height[index1],height[index2]) * (index2 - index1);
            }
        }
        return maxA;
    }
};