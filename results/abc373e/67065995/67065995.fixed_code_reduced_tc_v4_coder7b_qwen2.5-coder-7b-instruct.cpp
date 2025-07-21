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

    // Sort indices based on the current vote count
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[ord[i]];
    }

    vector<ll> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        int lid = n - m - (i >= n - m ? 1 : 0);
        ll target = (pref[n] - pref[lid]) / (n - lid);

        // Binary search to find the minimum additional votes needed
        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll additional_votes = mid + 1;
            ll total_votes = a[ord[i]] + additional_votes;
            ll remaining_votes = k - total_votes;
            ll votes_needed = pref[n] - pref[lid] - total_votes * (n - lid);

            if (votes_needed <= remaining_votes) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l != k + 1) {
            ans[ord[i]] = l;
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}