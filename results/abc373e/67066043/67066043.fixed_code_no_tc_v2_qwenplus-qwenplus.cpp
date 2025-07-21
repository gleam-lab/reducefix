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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Compute the number of remaining votes
    ll total_so_far = accumulate(all(a), (ll)0);
    ll remaining = k - total_so_far;

    // Create sorted version of a to help compute required votes
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    // Prepare prefix sums
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> result(n, -1);

    // For each candidate, determine minimum additional votes needed
    for (int i = 0; i < n; ++i) {
        ll low = 0, high = remaining;
        ll ans = -1;
        ll current_votes = a[i];

        // Binary search over X: number of additional votes for candidate i
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = current_votes + mid;

            // Find how many candidates can have strictly more than target
            // using binary search on sorted_a
            int idx = upper_bound(all(sorted_a), target) - sorted_a.begin();

            // We need at most (m-1) candidates with more votes than this one
            // So we ensure that at least (n - m + 1) candidates have <= target
            if (n - idx >= m) {
                // This candidate is already in top M by score
                ans = 0;
                break;
            }

            // Calculate how many extra votes are needed to bring the top M candidates below threshold
            int lid = max(0, idx);       // start from idx-th element
            int rid = min(n, n - m + 1); // want to make last (n - m + 1) candidates <= target

            if (lid < rid) {
                ll need = (rid - lid) * (target + 1) - (prefix[rid] - prefix[lid]);
                if (need <= remaining && mid <= remaining) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // lid >= rid means no adjustment needed
                ans = mid;
                high = mid - 1;
            }
        }

        result[i] = ans;
    }

    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';
}