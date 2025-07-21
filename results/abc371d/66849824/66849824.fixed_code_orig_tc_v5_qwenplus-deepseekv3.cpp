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

    vector<pair<ll, int>> sorted_X;
    for (int i = 0; i < N; ++i) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(sorted_X.begin(), sorted_X.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + P[sorted_X[i].second];
    }

    vector<ll> sorted_values(N);
    for (int i = 0; i < N; ++i) {
        sorted_values[i] = sorted_X[i].first;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        auto left_it = lower_bound(sorted_values.begin(), sorted_values.end(), L);
        auto right_it = upper_bound(sorted_values.begin(), sorted_values.end(), R);
        
        int left_idx = left_it - sorted_values.begin();
        int right_idx = right_it - sorted_values.begin();
        
        ll sum = prefix_sum[right_idx] - prefix_sum[left_idx];
        cout << sum << '\n';
    }

    return 0;
}