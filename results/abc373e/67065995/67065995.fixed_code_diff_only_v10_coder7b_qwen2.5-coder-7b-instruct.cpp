#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on the number of votes in ascending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    // Calculate the prefix sum array for sorted vote counts
    vector<ll> ps(n + 1);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[idx[i]];
    }

    // Initialize the answer array with infinity
    vector<ll> ans(n, INF);

    for (int i = 0; i < n; ++i) {
        int id = idx[i];
        ll cur_votes = a[id];

        // Binary search to find the minimum additional votes needed
        ll l = 0, r = k;
        while (l <= r) {
            ll mid = (l + r) / 2;
            int rank = upper_bound(ps.begin() + i + 1, ps.end(), cur_votes + mid) - ps.begin();
            int above = rank - (n - m);
            if (above < m) {
                ans[id] = min(ans[id], mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    // Output the results
    for (ll x : ans) {
        if (x == INF) cout << -1 << " ";
        else cout << x << " ";
    }
    cout << endl;

    return 0;
}