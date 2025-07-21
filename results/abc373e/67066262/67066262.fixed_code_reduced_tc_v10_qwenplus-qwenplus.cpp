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

    vector<int> ord(n);
    iota(all(ord), 0);

    // Sort candidates by current votes
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // Current candidate index
        ll low = 0, high = k + 1;

        while (low < high) {
            ll mid = (low + high) / 2;
            ll total = a[i] + mid;

            // Binary search to find how many candidates have votes > total
            int pos = upper_bound(sorted_a.begin(), sorted_a.end(), total) - sorted_a.begin();
            int cnt = n - pos;

            if (cnt >= m) {
                // Not enough, need more votes
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low <= k)
            res[i] = low;
    }

    for (auto x : res)
        cout << x << ' ';
}