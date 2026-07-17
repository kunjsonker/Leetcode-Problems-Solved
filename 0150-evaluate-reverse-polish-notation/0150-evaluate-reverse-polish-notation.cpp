class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        //the question can easily be solved using stack we use a for loop
        //we then push the integers and when we encounter an op
        //we maintain two variables and do the operation and push the answer 

        stack<int>st;


        for(int i=0;i<tokens.size();i++){

            if(tokens[i]=="+"){

                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                

                int ans=b+a;
                st.push(ans);

            }

            else if(tokens[i]=="-"){

                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                

                int ans=b-a;
                st.push(ans);

            }
            else if(tokens[i]=="*"){

                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int ans=b*a;
                st.push(ans);

            }
            else if(tokens[i]=="/"){

                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int ans=b/a;
                st.push(ans);

            }
            else{
                
                st.push(stoi(tokens[i]));


            }

            




        }
        return st.top();
        
    }
};