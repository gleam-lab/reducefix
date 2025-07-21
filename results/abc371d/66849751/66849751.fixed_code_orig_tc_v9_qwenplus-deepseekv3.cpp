#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<ll, ll>> points(N); // {X_i, P_i}
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first;
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].second;
    }
    
    // Sort points by X_i
    sort(points.begin(), points.end());
    
    // Create prefix sum array
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + points[i].second;
    }
    
    vector<ll> xs(N);
    for (int i = 0; i < N; ++i) {
        xs[i] = points[i].first;
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto left_it = lower_bound(xs.begin(), xs.end(), L);
        int left = left_it - xs.begin();
        
        // Find first X_i > R
        auto right_it = upper_bound(xs.begin(), xs.end(), R);
        int right = right_it - xs.begin();
        
        ll ans = prefix[right] - prefix[left];
        cout << ans << '\n';
    }
    
    return 0;
}