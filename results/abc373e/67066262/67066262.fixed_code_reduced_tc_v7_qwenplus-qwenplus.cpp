#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        K -= a[i];
    }

    // ord will store indices sorted by current votes
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    // b is the list of sorted current votes
    vector<ll> b = a;
    sort(all(b));

    // Compute prefix sum
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n, -1);

    for (int idx = 0; i < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = K + 1;

        while (low < high) {
            ll mid = (low + high) / 2;
            ll total_votes_i = a[i] + mid;

            // We want to find how many candidates can have strictly more votes than i
            // If more than M candidates can potentially have more votes, then it's invalid

            // Use binary search to find how many candidates could have more than total_votes_i
            int cnt = n - (upper_bound(b.begin(), b.end(), total_votes_i) - b.begin());

            // Now we need to make sure that at most M-1 candidates can have more votes than i
            // So we may need to increase i's votes further
            if (cnt <= m - 1) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // After binary search, check if it's possible
        ll total_votes_i = a[i] + low;
        int cnt = n - (upper_bound(b.begin(), b.end(), total_votes_i) - b.begin());

        if (low <= K && cnt <= m - 1) {
            ans[i] = low;
        } else {
            ans[i] = -1;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}