class Solution {
public:
    bool isUgly(int n) {
        //very easy math problem divide it by 5 3 2 while it can be divisible
        //check if the number remaining is 1 this means that it is divisible by 5 3 2 

        if(n==0) return false;

        while(n%5==0) n=n/5;
        while(n%3==0) n=n/3;
        while(n%2==0) n=n/2;
        if(n==1) return true;
        return false;
        
    }
};