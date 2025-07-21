#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> ord(n);
    iota(all(ord), 0);

    // We will sort candidates by their current votes
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = a[ord[i]];
    }

    // Prefix sum of sorted votes
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n);

    for (int i = 0; i < n; ++i) {
        int idx = ord[i]; // original index
        ll curr = a[idx];

        // Binary search on minimum X
        ll low = 0, high = k + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // Number of candidates that can have strictly more than curr + mid
            int cnt = n - (lower_bound(sorted_a.begin(), sorted_a.end(), curr + mid + 1) - sorted_a.begin());

            if (cnt < m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low > k) {
            res[idx] = -1; // Not possible within remaining votes
        } else {
            res[idx] = low;
        }
    }

    for (ll val : res) {
        cout << val << " ";
    }
    cout << "\n";
}