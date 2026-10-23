class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int k=-1;int flag1=-1;bool flag2=true;

        vector v=nums;
        // for(int i=0;i<n;i++)
        // {
        //     v[i]={nums[i],i};
        // }        

        // sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            if(v[i]!=i){
             // swap(v[i],v[v[i]]);
                flag2=false;
                k&=i;
                k&=v[i];
            }

            
        }
        if(flag2){
            return 0;
        }
        return k;
    }
};