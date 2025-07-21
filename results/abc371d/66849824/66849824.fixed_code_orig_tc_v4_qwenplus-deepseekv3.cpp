#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<ll, ll>> P(N); // (X_i, P_i)
    for (int i = 0; i < N; ++i) {
        cin >> P[i].first;
    }
    for (int i = 0; i < N; ++i) {
        cin >> P[i].second;
    }
    
    // Sort based on X_i to enable binary search
    sort(P.begin(), P.end());
    
    // Create prefix sum array
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + P[i].second;
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto it_l = lower_bound(P.begin(), P.end(), make_pair(L, 0LL));
        int l = distance(P.begin(), it_l);
        
        // Find first X_i > R
        auto it_r = upper_bound(P.begin(), P.end(), make_pair(R, LLONG_MAX));
        int r = distance(P.begin(), it_r);
        
        cout << (prefix[r] - prefix[l]) << '\n';
    }
    
    return 0;
}