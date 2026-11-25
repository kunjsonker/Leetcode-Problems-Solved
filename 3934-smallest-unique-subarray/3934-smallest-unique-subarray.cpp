class Solution {
public:

    int MOD = 1e9 + 7;
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1, r = n;
        int ans = n;

        while(l <= r){
            int m = l + (r - l) / 2;

            bool possible = check(nums, m, base);
            if(possible){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }

        return ans;

    }

    bool check(vector<int>& nums, int m, int base){
        int n = nums.size();
        int i = 0, j = 0;
        long long hash = 0;
        unordered_map<long long, int> mp;
        long long pow = findPowerUsingExpo(base, m - 1);


        while(j < n){
            hash = (hash * base + nums[j]) % MOD;
            if(j - i + 1 < m){
                j++;
            }else {
                mp[hash]++;
                hash = (hash - (pow * nums[i]) % MOD + MOD) % MOD;
                i++;
                j++;
            }
        }

        for(auto it : mp){
            if(it.second == 1) return true;
        }


        return false;
    }

    long long findPowerUsingExpo(long long a, long long base){
        if(base == 0) return 1;

        long long half = findPowerUsingExpo(a, base / 2);
        long long res = (half * half) % MOD;

        if(base % 2 == 1) res = (res * a) % MOD;
        return res;

    }


};