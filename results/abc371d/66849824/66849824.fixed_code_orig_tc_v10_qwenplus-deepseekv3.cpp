#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> P[i];
    
    // Create a vector of pairs (X_i, index) and sort it
    vector<pair<ll, int>> sorted_X(N);
    for (int i = 0; i < N; ++i) sorted_X[i] = {X[i], i};
    sort(sorted_X.begin(), sorted_X.end());
    
    // Create prefix sum array after sorting by X_i
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + P[sorted_X[i].second];
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto it_l = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair(L, 0));
        int l = it_l - sorted_X.begin();
        
        // Find first X_i > R
        auto it_r = upper_bound(sorted_X.begin(), sorted_X.end(), make_pair(R, INT_MAX));
        int r = it_r - sorted_X.begin();
        
        cout << prefix[r] - prefix[l] << '\n';
    }
    
    return 0;
}