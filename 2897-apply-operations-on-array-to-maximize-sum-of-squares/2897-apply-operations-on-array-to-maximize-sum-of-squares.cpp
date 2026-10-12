class Solution {
long long mod = 1e9 + 7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(32, 0);


        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    bit_count[i]++;
                }
            }
        }


        vector<int> largest_k(k, 0); 


        for (int i = 31; i >= 0; --i) {
            int count = bit_count[i];


            for (int j = 0; j < k && count > 0; ++j) {
                largest_k[j] |= (1 << i);
                count--;
            }
        }

        long long ans = 0;

        for (int num : largest_k) {
            ans = (ans + 1LL * num * num % mod) % mod;
        }

        return ans;
    }
};