class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //this can be done using bit manipulation instead of adding all indices and subtracting the sum of array

        //we maintain two xor see the x^x=0;x^0=x;

        int xor1=0,xor2=0;

        for(int i=0;i<nums.size();i++){

            xor1=nums[i]^xor1;
            xor2=xor2^i;



        }

        xor2^=nums.size(); // dont miss the last element
        return xor1^xor2;
        
    }
};