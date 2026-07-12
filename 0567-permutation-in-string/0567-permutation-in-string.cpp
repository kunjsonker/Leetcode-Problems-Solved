class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size()>s2.size()) return false;

        unordered_map<char,int>mpp1;
        for(auto it:s1){
            mpp1[it]++;
        }

        int left=0,right=s1.size()-1;
        while(right<s2.size()){
            unordered_map<char,int>mpp2;
            for(int i=left;i<=right;i++){
                
                mpp2[s2[i]]++;
                if(mpp1==mpp2) return true;
                

            }

            left++;
            right++;




        }
        return false;


        
    }
};