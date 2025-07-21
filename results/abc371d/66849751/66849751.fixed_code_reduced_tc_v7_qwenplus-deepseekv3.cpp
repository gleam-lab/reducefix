#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> X_index(N);
    for (int i = 0; i < N; ++i) {
        cin >> X_index[i].first;
        X_index[i].second = i;
    }
    sort(X_index.begin(), X_index.end());

    vector<int> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i + 1];
    }

    vector<int> original_index_sorted(N);
    vector<int> sorted_X(N);
    for (int i = 0; i < N; ++i) {
        sorted_X[i] = X_index[i].first;
        original_index_sorted[i] = X_index[i].second;
    }

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + P[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto lower_it = lower_bound(sorted_X.begin(), sorted_X.end(), L);
        auto upper_it = upper_bound(sorted_X.begin(), sorted_X.end(), R);
        int lower_pos = lower_it - sorted_X.begin();
        int upper_pos = upper_it - sorted_X.begin();

        ll sum = 0;
        for (int i = lower_pos; i < upper_pos; ++i) {
            int original_pos = original_index_sorted[i] + 1;
            sum += P[original_pos];
        }
        cout << sum << endl;
    }

    return 0;
}