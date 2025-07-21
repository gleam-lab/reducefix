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

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    // Sort candidates by current votes
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = a[idx[i]];
    }

    // Compute prefix sums of the sorted array
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int i = 0; i < n; ++i) {
        int pos = i; // position in sorted list
        ll low = 0, high = k + 1;

        while (low < high) {
            ll mid = (low + high) / 2;
            ll target = sorted_a[pos] + mid;

            // Find how many candidates have more than or equal to our target
            int upper = n - (upper_bound(sorted_a.begin(), sorted_a.end(), target) - sorted_a.begin());

            if (upper < m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low <= k) {
            res[idx[pos]] = low;
        } else {
            res[idx[pos]] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << max(0LL, res[i]) << " ";
    }

    return 0;
}