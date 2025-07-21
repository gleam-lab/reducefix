#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<ll, int>> X(N);  // (value, original index)
    for (int i = 0; i < N; ++i) {
        cin >> X[i].first;
        X[i].second = i;
    }
    
    vector<ll> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i + 1];
        P[i + 1] += P[i];
    }
    
    // Sort X based on value
    sort(X.begin(), X.end());
    
    vector<ll> sorted_values;
    vector<int> original_indices;
    for (const auto& p : X) {
        sorted_values.push_back(p.first);
        original_indices.push_back(p.second);
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto lower = lower_bound(sorted_values.begin(), sorted_values.end(), L);
        int l = distance(sorted_values.begin(), lower);
        
        // Find first X_i > R
        auto upper = upper_bound(sorted_values.begin(), sorted_values.end(), R);
        int r = distance(sorted_values.begin(), upper);
        
        // The sum is from P[l] to P[r] in the original order
        // But we need to process the original indices in sorted order
        // So we need to collect all original indices between l and r-1 in sorted_values
        // and sum their P values
        
        ll sum = 0;
        for (int i = l; i < r; ++i) {
            int original_idx = original_indices[i];
            sum += P[original_idx + 1] - P[original_idx];
        }
        
        cout << sum << '\n';
    }
    
    return 0;
}