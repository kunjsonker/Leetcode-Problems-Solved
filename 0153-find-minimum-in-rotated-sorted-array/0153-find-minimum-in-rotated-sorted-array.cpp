class Solution {
public:
    int findMin(vector<int>& nums) {

        //this is a question of modified binary search



        int left=0,right=nums.size()-1;
        // int minimum=INT_MAX;

        while(left<right){
            int mid=left+(right-left)/2;

            if(nums[mid]>=nums[right]){
                // minimum=min(minimum,nums[mid]);
                left=mid+1;
            }

            if(nums[mid]<nums[right]){
                // minimum=min(minimum,nums[mid]);
                right=mid;
            }

            
        }
        return nums[left];



        
    }
};