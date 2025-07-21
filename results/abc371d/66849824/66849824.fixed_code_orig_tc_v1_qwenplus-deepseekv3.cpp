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
    
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + P[i];
    }
    
    vector<pair<ll, int>> sorted_X;
    for (int i = 0; i < N; ++i) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(sorted_X.begin(), sorted_X.end());
    
    vector<ll> sorted_values;
    for (const auto& p : sorted_X) {
        sorted_values.push_back(p.first);
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(sorted_values.begin(), sorted_values.end(), L);
        auto it_r = upper_bound(sorted_values.begin(), sorted_values.end(), R);
        
        int l = it_l - sorted_values.begin();
        int r = it_r - sorted_values.begin();
        
        ll ans = prefix[r] - prefix[l];
        cout << ans << '\n';
    }
    
    return 0;
}