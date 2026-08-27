class Solution {
private:
    void dfs(int node,vector<int>adjLs[],vector<int> &vis){
        vis[node]=1;
        for(auto it: adjLs[node]){
            if(!vis[it]) dfs(it,adjLs,vis);
        }


    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //this problem is from conneced graphs
        //we can use any traversal
        //given is an adjecency matrix we can convert it into adj list

        int v=isConnected.size();

        //creating a adjlist using matrix
        vector<int>adjLs[v];


        for(int i=0;i<v;i++){
            for(int j=i;j<v;j++){
                if (isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);

                }
            }
            

        }

        // now create a visited array for keeping count of number of nodes

        vector<int>vis(v,0);
        
        int cnt=0;

        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;

        
    }
};