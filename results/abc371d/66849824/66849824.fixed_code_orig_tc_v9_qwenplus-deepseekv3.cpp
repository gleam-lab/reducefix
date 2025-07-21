#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N+1);
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> P[i+1];
        P[i+1] += P[i];
    }

    vector<pair<ll, int>> indexed_X;
    for (int i = 0; i < N; ++i) {
        indexed_X.emplace_back(X[i], i);
    }
    sort(indexed_X.begin(), indexed_X.end());

    vector<ll> sorted_P_prefix(N+1);
    sorted_P_prefix[0] = 0;
    for (int i = 0; i < N; ++i) {
        int idx = indexed_X[i].second;
        sorted_P_prefix[i+1] = sorted_P_prefix[i] + (P[idx+1] - P[idx]);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        auto it_l = lower_bound(indexed_X.begin(), indexed_X.end(), make_pair(L, 0));
        auto it_r = upper_bound(indexed_X.begin(), indexed_X.end(), make_pair(R, N));
        int l = distance(indexed_X.begin(), it_l);
        int r = distance(indexed_X.begin(), it_r);
        cout << sorted_P_prefix[r] - sorted_P_prefix[l] << '\n';
    }

    return 0;
}