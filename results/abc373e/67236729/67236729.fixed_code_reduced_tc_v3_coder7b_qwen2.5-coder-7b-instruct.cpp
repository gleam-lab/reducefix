#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[n - i];
    }

    vector<ll> results(n);
    for (int i = 0; i < n; ++i) {
        ll target = a[i];
        int rank = n - i;
        ll needed = 0;

        if (rank <= m) {
            needed = 0;
        } else {
            ll excess = prefix_sum[m - 1] - prefix_sum[rank - m - 1];
            needed = max(0LL, target + 1 - excess);
        }

        results[i] = needed;
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}