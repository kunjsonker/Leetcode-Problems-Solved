class Solution {
public:

    bool canfinish(vector<int>&piles,int mid,int h){

        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+mid-1)/mid; //IMPORTANT: (a+b-1)/b gives always ceil value 
        }
        return hours<=h;



    }


    int minEatingSpeed(vector<int>& piles, int h) {

        //this is a must solve problem
        //the problem can be solved using binary search 

        int maxbananas=1;
        for(int i=0;i<piles.size();i++){
            maxbananas=max(maxbananas,piles[i]);
        }

        //now apply binary search between 1 to largest stack of bananas 
        int left=1,right=maxbananas;

        while(left<right){

            int mid = left+(right-left)/2;

            if(canfinish(piles,mid,h)){
                right=mid;
            }
            else{
                left=mid+1;
            }






        }
        return right;




        
    }
};