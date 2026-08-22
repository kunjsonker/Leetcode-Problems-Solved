class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        vector<int>res(nums.size(),0);
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            left[i]=s;
            s+=nums[i];
        }
        s=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            right[i]=s;
            s+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        res[i]=abs(left[i]-right[i]);
        return res;
    }
};