class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<vector<int>>ans;
        set<vector<int>>ss;


        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            vector<int>temp;
            while(j<k){
                
                if(nums[i]+nums[j]+nums[k]==0){
                    ss.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;

                }
                else {
                    k--;

                }


                
            }

        }

        // for(auto it:ans){
        //     vector<int>temp=it;
        //     sort(it.begin(),it.end())
        //     it.second.push_back(temp);
        // }

        // return ans.push_back(ss.begin(),ss.end());

        vector<vector<int>> ans(ss.begin(), ss.end());
        return ans;
        




        
    }
};