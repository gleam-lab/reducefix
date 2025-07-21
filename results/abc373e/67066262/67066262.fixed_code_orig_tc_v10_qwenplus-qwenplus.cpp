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

    // Precompute prefix sums of sorted votes
    vector<ll> sorted_a(n), prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = a[idx[i]];
    }
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int i = 0; i < n; ++i) {
        int pos = i; // position in the sorted list
        ll low = 0, high = k + 1;

        while (low < high) {
            ll mid = (low + high) / 2;
            ll x = a[idx[pos]] + mid;

            // We need to find how many candidates have strictly more than x votes
            // Binary search for the first candidate with votes > x
            int cnt = n - (upper_bound(sorted_a.begin(), sorted_a.end(), x) - sorted_a.begin());

            if (cnt >= m) {
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

    for (auto v : res) {
        cout << v << " ";
    }
}