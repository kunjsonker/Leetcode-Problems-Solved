class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //this is also a problem of dynamic sliding window
        //use hashmap to keep the index value as value in mapp

        int result=0;
        int left=0,right=0;

        unordered_map<char,int>mpp;

        for(;right<s.size();right++){
            int idx=-1;
            
            auto it=mpp.find(s[right]);


            if(it==mpp.end()){
                idx=-1;
            }
            else{
                idx=it->second;
            }

            if(idx!=-1 && idx>=left){
                
                result=max(result,(right-1-left+1));
                left=idx+1;
            }

            mpp[s[right]]=right;
            

            
        }

        return result=max(result,(right-1-left+1));

        
        

        



        
    }
};