class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++){
            
            vector<int> map(101, 0);
            int c = 0;
            for (int j = i; j < nums.size(); j++){
                if (map[nums[j]]++ == 0)
                    c++;
                res += 1LL * c *c;
                
            }   
        }
        return res;

    }
};