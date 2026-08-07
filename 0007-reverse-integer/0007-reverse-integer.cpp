class Solution {
public:
    int reverse(int x) {
        
        long long  n=-1;
        if(x<0){
            x=x*n;
            long long rev=0;
        while(x>0){
            long long modd=x%10;
            rev=rev*10+modd;
            x=x/10;
        }
        if(rev>INT_MAX) return 0;
        return rev*n;
        }
        else{
        long long rev=0;
        while(x>0){
            long long modd=x%10;
            rev=rev*10+modd;
            x=x/10;
        }
        if(rev>INT_MAX) return 0;
        return rev;
    }
    }
};