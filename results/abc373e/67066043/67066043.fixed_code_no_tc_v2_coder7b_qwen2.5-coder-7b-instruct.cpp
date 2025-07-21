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
        k -= a[i];
    }

    // Sort indices based on vote counts in descending order
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = a[ord[i]] + pref[i];
    }

    // Initialize answer array with -1 (impossible to win)
    vector<ll> ans(n, -1);

    // Iterate over candidates
    for (int i = 0; i < n; i++) {
        // If candidate i can already win, set answer to 0
        if (n - i - 1 < m) {
            ans[ord[i]] = 0;
            continue;
        }

        // Binary search for the minimum number of additional votes needed
        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            // Calculate the total votes needed for candidate i to win
            ll needed_votes = a[ord[i]] + mid;
            // Calculate the sum of votes of the next m candidates
            ll sum_next_m = pref[min(i + m, n)] - pref[i + 1];
            // Check if candidate i can still win after receiving mid votes
            if (needed_votes > sum_next_m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // If l exceeds k, it means no valid solution exists
        if (l > k) {
            ans[ord[i]] = -1;
        } else {
            ans[ord[i]] = l;
        }
    }

    // Output the results
    for (auto i : ans) cout << i << ' ';
    return 0;
}