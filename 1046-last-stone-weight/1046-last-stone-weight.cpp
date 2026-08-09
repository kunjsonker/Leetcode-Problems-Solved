class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //use min heap for heaviest element

        priority_queue<int>pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int one=pq.top();
            pq.pop();
            int two=pq.top();
            pq.pop();
            if(one!=two){
                int temp=one-two;
                pq.push(temp);

            } 


        }
        return pq.empty() ? 0:pq.top();
        
    }
};