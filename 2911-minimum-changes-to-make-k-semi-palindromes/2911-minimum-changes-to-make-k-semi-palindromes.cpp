class Solution {
private:
    int memo[201][101] = {};

    int memo_s[201][201];
    int memo_d[201][201];

public:
    int minimumChanges(const string &s, int k, int i = 0)
    {
        const int N = s.size();

        memset(memo_s, 1, sizeof(memo_s));
        for (int d = 1; d <= N/2; d++)
        {
 
            memset(memo_d, 0, sizeof(memo_d)); 
            for (int len = 2 * d; len <= N; len += d)
            {
                for (int idx = 0; idx + len <= N; idx++)
                {
                    int ops = 0;
                    for (int offset = 0; offset < d; offset++)
                        ops += s[idx + offset] != s[idx + len - (d - offset)];

                    memo_d[idx][len] = ops + memo_d[idx + d][len - 2 * d];
                    memo_s[idx][len] = min(memo_s[idx][len],
                                         memo_d[idx][len]);
                }

            }
        }

        return solve(0, k, s);
    }

private:
    int solve(int idx, int k, const string& s)
    {
        const int N = s.size();
        if (idx >= s.size() || k <= 0)
            return idx == N && k == 0 ? 0 : 10000;

        if (memo[idx][k] == 0)
        {
            memo[idx][k] = 10000;

            for (int len = 2; idx + len <= s.size(); ++len)
            {
                int result = 1 + memo_s[idx][len] + solve(idx + len, k - 1, s);

                memo[idx][k] = min(memo[idx][k], result);
                                   
            }
        }

        return memo[idx][k] - 1;
    }
};