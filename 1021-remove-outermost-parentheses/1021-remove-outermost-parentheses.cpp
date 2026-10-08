class Solution {
public:
    string removeOuterParentheses(string s) {
       int f=0;
       int n=s.size();
       vector<string> v;
       string st="";
       for(int i=0;i<n;i++){
        if(s[i]=='(')   f++;
        else    f--;
        st+=s[i];
        if(f==0){
            v.push_back(st);
            st="";
            f=0;
        }
       }
       string ans="";
       for(auto it:v){
        for(int i=1;i<it.size()-1;i++){
            ans+=it[i];
        }
       }
       return ans;
    }
};