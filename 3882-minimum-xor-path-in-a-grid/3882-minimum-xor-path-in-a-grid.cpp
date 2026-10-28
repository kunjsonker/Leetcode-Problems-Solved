class Solution{
public:
    int minCost(vector<vector<int>> &grid){
        int n = grid.size() , m = grid[0].size();

        vector<unordered_set<int>> prev(m);

        for(int i = 0 ; i < n ; i++){
            vector<unordered_set<int>> curr(m);
            for(int j = 0 ; j < m ; j++){
                if(i == 0 && j == 0) curr[j].insert(grid[i][j]);
                if(i > 0) for(int xorr : prev[j]) curr[j].insert(xorr ^ grid[i][j]);
                if(j > 0) for(int xorr : curr[j - 1]) curr[j].insert(xorr ^ grid[i][j]);
            }
            swap(prev , curr);
        }

        int mini = 2e9;
        for(int xorr : prev[m - 1]) mini = min(mini , xorr);

        return mini;
    }
};