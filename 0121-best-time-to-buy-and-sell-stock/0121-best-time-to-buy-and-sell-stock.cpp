class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //this is the easiest problem of dynamic sliding window
        //while traversing the array we will always try to to sell it
        //if we encounter a minimum we will keep that as our buying point


        int minsofar=prices[0];
        int maxprofit=0;

        for(int i=0;i<prices.size();i++){

            if(prices[i]<minsofar){
                minsofar=prices[i];
            }

            int temp=prices[i]-minsofar;

            maxprofit=max(maxprofit,temp);





        }

        return maxprofit;
    }
};