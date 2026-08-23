#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    struct Query {
        int l;
        int r;
        int idx;
    };

    std::vector<bool> validSubarrays(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
        int n = (int)nums.size();
        int q = (int)queries.size();

        std::vector<int> vals = nums;
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
        std::vector<int> comp(n);
        for (int i = 0; i < n; ++i) {
            comp[i] = (int)(std::lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin());
        }
        std::vector<int> freq((int)vals.size() + 1, 0);

        std::vector<Query> qs(q);
        for (int i = 0; i < q; ++i) {
            qs[i].l = queries[i][0];
            qs[i].r = queries[i][1];
            qs[i].idx = i;
        }

        int block = std::max(1, (int)std::sqrt((double)n));
        std::sort(qs.begin(), qs.end(), [block](const Query& a, const Query& b) {
            int ba = a.l / block;
            int bb = b.l / block;
            if (ba != bb) return ba < bb;
            if (ba % 2 == 1) return a.r > b.r;
            return a.r < b.r;
        });

        std::vector<bool> ans(q, false);
        int curL = 0;
        int curR = -1;
        int distinct = 0;
        int odd = 0;

        auto add = [&](int pos) {
            int val = comp[pos];
            int f = freq[val];
            if (f == 0) ++distinct;
            if (f % 2 == 1) --odd;
            ++freq[val];
            if (freq[val] % 2 == 1) ++odd;
        };

        auto remove = [&](int pos) {
            int val = comp[pos];
            int f = freq[val];
            if (f % 2 == 1) --odd;
            --freq[val];
            if (freq[val] == 0) --distinct;
            if (freq[val] % 2 == 1) ++odd;
        };

        for (const Query& qu : qs) {
            int len = qu.r - qu.l + 1;
            if (len % 2 == 1 || len < 2 * k) {
                ans[qu.idx] = false;
                continue;
            }

            while (curL > qu.l) add(--curL);
            while (curR < qu.r) add(++curR);
            while (curL < qu.l) remove(curL++);
            while (curR > qu.r) remove(curR--);

            ans[qu.idx] = (distinct == k && odd == 0);
        }

        return ans;
    }
};