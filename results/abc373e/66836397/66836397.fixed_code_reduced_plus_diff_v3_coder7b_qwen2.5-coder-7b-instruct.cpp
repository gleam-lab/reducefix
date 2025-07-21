#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    ll current_total = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        current_total += a[i];
    }

    ll remaining_votes = k - current_total;
    sort(a.begin(), a.end());

    vector<ll> prefix_sum(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    vector<ll> result(n);
    for (ll i = 0; i < n; ++i) {
        ll max_votes_other_can_get = prefix_sum[n] - prefix_sum[i + 1];
        ll needed_votes = max(0LL, max_votes_other_can_get - a[i] + 1);

        if (needed_votes <= remaining_votes) {
            result[i] = needed_votes;
        } else {
            result[i] = -1;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << result[i] << " \n"[i == n - 1];
    }

    return 0;
}