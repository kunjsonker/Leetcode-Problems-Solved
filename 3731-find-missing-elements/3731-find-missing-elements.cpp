class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int a=nums[n];
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }

        vector<int>v;
        for (int i = nums[0]; i <= a; ++i) {
            if (mpp.find(i) == mpp.end()) { 
                v.push_back(i);      
            }
        }
        return v;




        
    }
};