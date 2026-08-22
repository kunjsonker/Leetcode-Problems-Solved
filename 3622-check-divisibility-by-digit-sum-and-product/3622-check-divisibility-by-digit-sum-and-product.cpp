class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1;
        int sum=0;
        int org=n;

        while(n>0){
            int mod=n%10;
            product*=mod;
            sum+=mod;
            n=n/10;
        }
        if(org%(sum+product)==0) return true;

        return false;
        
    }
};