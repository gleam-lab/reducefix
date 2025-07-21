#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<ll, ll>> ab(n);
        for (int i=0; i<n; i++) cin >> ab[i].first;
        for (int i=0; i<n; i++) cin >> ab[i].second;
        
        // Sort by A values
        sort(ab.begin(), ab.end());
        
        ll min_value = LLONG_MAX;
        
        // We need to find the minimum value of the expression for each possible subset of size K
        for (int i = 0; i <= n - k; i++) {
            ll sum = 0;
            ll max_a = ab[i].first;
            for (int j = i; j < i + k; j++) {
                sum += ab[j].second;
            }
            ll current_value = max_a * sum;
            min_value = min(min_value, current_value);
        }
        
        cout << min_value << '\n';
    }
    return 0;
}