#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end(), greater<ll>());
    
    vector<ll> prefix_sum(n + 1);
    for (ll i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    
    vector<ll> result(n);
    
    for (ll i = 0; i < n; i++) {
        ll votes_needed = 0;
        for (ll j = 0; j < n; j++) {
            if (j != i) {
                votes_needed += max(0LL, a[j] - a[i] + 1);
            }
        }
        if (votes_needed > K) {
            result[i] = -1;
        } else {
            result[i] = 0;
        }
    }
    
    for (ll i = 0; i < n; i++) {
        if (result[i] != -1) {
            ll needed = (prefix_sum[n] - prefix_sum[i + 1]) - (prefix_sum.back() - prefix_sum[i]);
            result[i] = max(result[i], needed);
        }
    }
    
    for (ll i = 0; i < n; i++) {
        if (result[i] == -1) {
            continue;
        }
        ll total_votes = prefix_sum.back();
        ll votes_for_i = prefix_sum[i + 1];
        ll required_votes = (total_votes - votes_for_i) + 1;
        result[i] = max(result[i], required_votes);
    }
    
    for (ll i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}