ostream& operator<<(ostream& os, vector<int> v);

void heapify(vector<int>& nums, int index, int size){
    int n = size;
    int left = 2*(index+1)-1;
    int right = 2*(index+1);
    int largest = index;

    if(left < n && nums[left] > nums[largest]) largest = left;
    if(right < n && nums[right] > nums[largest]) largest = right;
    if(largest != index){
        swap(nums[index], nums[largest]);
        //cout << nums << "\n";
        heapify(nums, largest, size);
    }
    return;
}   




class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //build max heap
        for(int i = n/2 -1; i >= 0; i--){
            heapify(nums,i,n);
        }
        for (int i = n-1; i > 0; i--){
            swap(nums[i],nums[0]);
            for(int j = (i-1)/2-1; j>=0; j--){
                heapify(nums,j,i-1);
            }
            //cout << nums << endl;
        }
        //cout << nums << "\n";
        return nums[n-k];
    }
};

ostream& operator<<(ostream& os, vector<int> v){
    for(auto i: v){
        os << i << " ";
    }
    return os;
}
