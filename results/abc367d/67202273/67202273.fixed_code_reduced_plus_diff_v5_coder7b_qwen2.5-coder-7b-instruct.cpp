#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n), prefix_sum(n + 1, 0);
    unordered_map<ll, ll> count;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
        count[prefix_sum[i + 1]]++;
    }

    ll result = 0;
    for (ll i = 0; i <= n; ++i) {
        result += count[prefix_sum[i]];
        count[prefix_sum[i]]--;
    }

    cout << result << '\n';

    return 0;
}