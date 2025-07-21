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

    // Create sorted copy of votes
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    // Prepare prefix sums
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> result(n, -1);

    // For each candidate, binary search on minimum required votes
    for (int i = 0; i < n; i++) {
        ll low = 0;
        ll high = k;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = a[i] + mid;

            // Find number of candidates with votes > target
            // We use binary search to find the first index where votes > target
            int idx = n - (upper_bound(all(sorted_a), target) - sorted_a.begin());

            if (idx < m) {
                // Candidate can be among top M -> victory
                ans = mid;
                high = mid - 1;
            } else {
                // Not guaranteed victory
                low = mid + 1;
            }
        }

        result[i] = (ans == -1 ? -1 : ans);
    }

    for (auto x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}