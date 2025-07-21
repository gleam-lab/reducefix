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

    // Calculate total unassigned votes
    ll total_assigned = accumulate(all(a), (ll)0);
    ll remaining = k - total_assigned;

    vector<int> ord(n);
    iota(all(ord), 0);

    // Sort candidates by current votes
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    // Precompute prefix sums of the sorted votes
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> result(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index of candidate with sorted rank idx
        ll low = 0, high = remaining + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = a[i] + mid;

            // Binary search to find how many candidates have votes > target
            int pos = upper_bound(sorted_a.begin(), sorted_a.end(), target) - sorted_a.begin();

            // We want at least (n - M) candidates with votes > target
            if (pos >= n - m + 1) {
                // Too many people ahead, need more votes
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (low > remaining) {
            result[i] = -1; // Cannot guarantee win
        } else {
            // Now calculate the minimal X that pushes candidate i into top M
            ll needed = low;
            result[i] = needed;
        }
    }

    for (ll val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}