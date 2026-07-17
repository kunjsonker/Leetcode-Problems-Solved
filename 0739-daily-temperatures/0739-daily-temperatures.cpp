class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        //this question will be solved using stack
        //we will take a for loop from roght to left and store indices
        //check if the picked elemnt of the array is more than top of stack
        //if it is then pop the stack until the stack has greater element than the picked 
        //element of the array
        int n=temperatures.size();

        vector<int>ans(n,0);
        stack<int>st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            
            }
            

            if(!st.empty()){
                ans[i]=st.top()-i;
            }

            st.push(i);



        }
        return ans;





        
    }
};