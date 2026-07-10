class Solution {
public:
    bool isValid(string s) {
        //this is the question of stack


        if(s.empty()) return true;
        stack<char>stackk;

        for(int i=0;i<s.size();i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                stackk.push(s[i]);
            }
            else{

            if (stackk.empty()) return false;

            if(s[i] == ')' && stackk.top() == '(' ){
                stackk.pop();
                
            }

            else if(s[i] == '}' && stackk.top() == '{' ){
                stackk.pop();
            }

            else if(s[i] == ']' && stackk.top() == '[' ){
                stackk.pop();
            }
            
            else{
                return false;
            }

            }







            

        }
        return stackk.empty();
        
    }
};