#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> prefix_sum(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    vector<ll> result(n);
    for (ll i = 0; i < n; i++) {
        if (i + 1 >= m) {
            result[i] = 0;
        } else {
            ll needed_votes = (prefix_sum[n] - prefix_sum[i + 1]) - (n - i - 1 - (m - 1)) * a[i];
            if (needed_votes > k) {
                result[i] = -1;
            } else {
                result[i] = max(0LL, (needed_votes + k) / (n - i - 1));
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}