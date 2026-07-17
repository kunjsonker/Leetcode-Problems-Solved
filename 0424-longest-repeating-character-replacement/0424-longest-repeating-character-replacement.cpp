class Solution {
public:
    int characterReplacement(string s, int k) {

        //sliding window
        //we will use hashmap in this question with dynamic sliding window

        unordered_map<char,int>mpp;

        int l=0;
        int maxx=0;int ans=0;

        for(int r=0;r<s.size();r++){
            
            mpp[s[r]]++;
            maxx=max(maxx,mpp[s[r]]);

            if((r-l+1)-maxx>k){
                mpp[s[l]]--;
                l++;
                
            }
            
            ans=max(maxx,r-l+1);
        }
        return ans;



        






        
    }
};