class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> temp;
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(temp[i]);
        }
        return ans;
        
    }
};