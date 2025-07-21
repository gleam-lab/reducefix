#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    for (ll &a : A) cin >> a;
    vector<pair<ll, int>> candidates(A.begin(), A.end());
    sort(candidates.begin(), candidates.end());

    // Calculate prefix sums
    vector<ll> prefix(n);
    prefix[0] = candidates[0].first;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        // Binary search to find the minimum votes needed to ensure victory
        auto bsearch = [&](ll l, ll r) -> ll {
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll num = (mid + 1) * (n - m - (i >= n - m)) - (prefix[n - m - 1] - (i >= n - m ? prefix[n - 2] : prefix[i - 1]));
                if (num >= k) return r = mid;
                l = mid + 1;
            }
            return l;
        };

        ll votes_needed = bsearch(0, k - (prefix[n - m - 1] - (i >= n - m ? prefix[n - 2] : prefix[i - 1])) + 1);
        if (votes_needed <= k - (prefix[n - m - 1] - (i >= n - m ? prefix[n - 2] : prefix[i - 1]))) {
            ans[i] = votes_needed;
        } else {
            ans[i] = -1;
        }
    }

    for (ll a : ans) cout << a << ' ';
    cout << '\n';
    return 0;
}