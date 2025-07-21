#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, K;
    cin >> n >> m >> K;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        K -= a[i];
    }

    sort(rbegin(a), rend(a));

    vector<ll> prefix_sum(n + 1);
    partial_sum(rbegin(a), rend(a), begin(prefix_sum) + 1);

    vector<ll> result(n);
    for (ll i = 0; i < n; ++i) {
        if (a[i] >= (prefix_sum[n] - prefix_sum[i + 1]) + (m - i - 1)) {
            result[i] = 0;
        } else {
            ll remaining_votes_needed = (prefix_sum[n] - prefix_sum[i + 1]) + (m - i - 1) - a[i];
            result[i] = remaining_votes_needed;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}