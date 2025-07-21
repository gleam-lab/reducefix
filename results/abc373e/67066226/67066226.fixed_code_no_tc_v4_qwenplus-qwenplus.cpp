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
    ll total_so_far = accumulate(all(a), 0LL);
    ll remaining = k - total_so_far;

    // For each candidate, we'll compute how many additional votes they need
    vector<ll> res(n, -1);

    // Create sorted list of current vote counts
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    for (int i = 0; i < n; i++) {
        ll my_votes = a[i];

        // We want to find the minimum X such that even if other candidates get as many votes as possible,
        // this candidate still has at least M candidates with strictly less than (my_votes + X)

        // The idea is to make sure that the (n-M)th largest vote count is <= my_votes + X

        // Find the (n-M+1)th largest current vote count among other candidates
        // This is the highest vote count that can potentially be above ours
        ll threshold;
        if (m == n) {
            // All candidates must have fewer votes than us
            threshold = my_votes + 1;
        } else {
            int pos = upper_bound(all(sorted_a), my_votes) - sorted_a.begin();
            if (pos >= n - m + 1) {
                // Already in top M-1, no need for additional votes
                res[i] = 0;
                continue;
            }
            threshold = sorted_a[n - m + (pos <= n - m ? 0 : 1)];
        }

        ll needed = max(0LL, threshold - my_votes);
        if (needed > remaining) {
            res[i] = -1;
        } else {
            res[i] = needed;
        }
    }

    for (auto x : res) cout << x << " ";
    cout << "\n";
}