#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate remaining votes
    ll total_so_far = accumulate(all(a), 0LL);
    ll remaining = k - total_so_far;

    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int i = 0; i < n; ++i) {
        ll low = 0, high = remaining;
        ll candidate_votes = a[i];
        ll ans = -1;

        // Binary search on the number of extra votes needed
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_after = candidate_votes + mid;

            // Find how many candidates have votes strictly greater than total_after
            // Using the sorted array
            int idx = upper_bound(all(sorted_a), total_after) - sorted_a.begin();

            // We want at least (n - M) candidates with votes <= total_after (including current candidate)
            // So there can be at most M-1 candidates with votes > total_after
            if (n - idx <= M - 1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans >= 0 && ans <= remaining)
            res[i] = ans;
        else
            res[i] = -1;
    }

    for (auto x : res) cout << x << " ";
    cout << "\n";
}