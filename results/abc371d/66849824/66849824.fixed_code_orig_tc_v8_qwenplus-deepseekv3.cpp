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

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        auto lower = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair(L, 0));
        auto upper = upper_bound(sorted_X.begin(), sorted_X.end(), make_pair(R, N));

        int l = (lower == sorted_X.end()) ? N : lower->second;
        int r = (upper == sorted_X.end()) ? N : upper->second;

        if (l < r) {
            cout << prefix[r] - prefix[l] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}