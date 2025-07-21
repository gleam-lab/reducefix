#include <bits/stdc++.h>
using namespace std;

using __int128 = signed __int128;

vector<__int128> prefix_sums;
map<int, int> x_to_ptr;

__int128 get_range_sum(int L, int R) {
    if (L == 0) return prefix_sums[R];
    return prefix_sums[R] - prefix_sums[L - 1];
}

int main() {
    int N;
    cin >> N;
    vector<__int128> P(N + 1), X(N);
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    for (int i = 0; i < N; ++i) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        if (X_l == x_to_ptr.end()) {
            L = N;
        } else {
            L = (*X_l).second;
        }
        if (X_r == x_to_ptr.end()) {
            R = N;
        } else {
            R = (*X_r).second;
        }
        cout << get_range_sum(L, R) << endl;
    }
    return 0;
}