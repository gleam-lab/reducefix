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
    
    // Create prefix sums
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + P[i];
    }
    
    // Create a sorted list of X values with their indices
    vector<pair<ll, int>> sorted_X;
    for (int i = 0; i < N; ++i) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(sorted_X.begin(), sorted_X.end());
    
    vector<ll> sorted_X_values;
    for (auto& p : sorted_X) {
        sorted_X_values.push_back(p.first);
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find first X >= L
        auto it_l = lower_bound(sorted_X_values.begin(), sorted_X_values.end(), L);
        int l = it_l - sorted_X_values.begin();
        
        // Find first X > R
        auto it_r = upper_bound(sorted_X_values.begin(), sorted_X_values.end(), R);
        int r = it_r - sorted_X_values.begin();
        
        // Get indices in original array
        int first = (l < sorted_X.size()) ? sorted_X[l].second : N;
        int last = (r > 0) ? sorted_X[r - 1].second : -1;
        
        if (first > last) {
            cout << "0\n";
        } else {
            ll ans = prefix[last + 1] - prefix[first];
            cout << ans << '\n';
        }
    }
    
    return 0;
}