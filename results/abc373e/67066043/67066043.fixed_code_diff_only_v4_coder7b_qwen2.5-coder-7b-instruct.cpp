#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    // Sort the votes in ascending order
    sort(a.begin(), a.end());

    // Calculate the prefix sum array
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        // Calculate the maximum votes needed for candidate i to win
        ll max_votes_needed = a[n - 1] + 1 + (m - 1) * a[n - m];

        // Check if candidate i can win with additional votes
        if (a[i] + k >= max_votes_needed) {
            ans[i] = 0;
        } else {
            // Binary search to find the minimum additional votes needed
            ll l = 0, r = k;
            while (l < r) {
                ll mid = (l + r) / 2;
                if (a[i] + mid + pref[n] - pref[i + 1] >= max_votes_needed) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = l;
        }
    }

    for (ll x : ans) cout << x << " ";
    return 0;
}