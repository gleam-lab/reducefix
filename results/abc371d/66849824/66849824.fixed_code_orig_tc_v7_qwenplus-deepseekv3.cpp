#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    map<ll, int> x_to_idx;
    for (int i = 0; i < N; ++i) {
        x_to_idx[X[i]] = i;
    }
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + P[i];
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        auto it_l = x_to_idx.lower_bound(L);
        auto it_r = x_to_idx.upper_bound(R);
        
        int l = (it_l == x_to_idx.end()) ? N : it_l->second;
        int r = (it_r == x_to_idx.end()) ? N : it_r->second;
        
        ll ans = prefix[r] - prefix[l];
        cout << ans << '\n';
    }
    
    return 0;
}