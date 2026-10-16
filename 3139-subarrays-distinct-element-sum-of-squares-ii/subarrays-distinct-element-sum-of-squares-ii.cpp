
class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    vector<ll> s, sq, lazy;
    int n;

    void apply(int p, int l, int r, ll v) {
        sq[p] = (sq[p] + 2 * v * s[p] + (r-l+1LL)*v*v) % MOD;
        s[p] = (s[p] + (r-l+1LL)*v) % MOD;
        lazy[p] = (lazy[p] + v) % MOD;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        int m = (l + r) / 2;
        apply(p*2, l, m, lazy[p]);
        apply(p*2+1, m+1, r, lazy[p]);
        lazy[p] = 0;

        update(p*2, l, m, ql, qr);
        update(p*2+1, m+1, r, ql, qr);

        s[p] = (s[p*2] + s[p*2+1]) % MOD;
        sq[p] = (sq[p*2] + sq[p*2+1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        s.assign(4*n, 0);
        sq.assign(4*n, 0);
        lazy.assign(4*n, 0);

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int j = 0; j < n; j++) {
            int l = last[nums[j]] + 1;
            update(1, 0, n-1, l, j);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
