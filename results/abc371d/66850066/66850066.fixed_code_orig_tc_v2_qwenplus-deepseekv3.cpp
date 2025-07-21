#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
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

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + P[i];
    }

    vector<pair<ll, int>> sorted_X;
    for (int i = 0; i < N; ++i) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(sorted_X.begin(), sorted_X.end());

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        int l = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair(L, 0)) - sorted_X.begin();
        int r = upper_bound(sorted_X.begin(), sorted_X.end(), make_pair(R, N)) - sorted_X.begin() - 1;

        if (l > r) {
            cout << 0 << '\n';
        } else {
            int actual_l = sorted_X[l].second;
            int actual_r = sorted_X[r].second;
            if (actual_l > actual_r) {
                cout << 0 << '\n';
            } else {
                cout << prefix_sum[actual_r + 1] - prefix_sum[actual_l] << '\n';
            }
        }
    }

    return 0;
}