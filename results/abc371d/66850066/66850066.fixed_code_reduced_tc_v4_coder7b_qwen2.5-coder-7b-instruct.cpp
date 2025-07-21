#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    for(int i = 0; i < N; ++i) cin >> P[i];

    vector<ll> cum_sum(P);
    for(int i = 1; i < N; ++i) cum_sum[i] += cum_sum[i - 1];

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        auto it_L = lower_bound(all(X), L);
        auto it_R = upper_bound(all(X), R);
        int idx_L = it_L - begin(X);
        int idx_R = it_R - begin(X) - 1;

        if(idx_L == N || X[idx_L] > R) --idx_L;
        if(idx_R == -1 || X[idx_R] < L) ++idx_R;

        if(idx_L >= idx_R) cout << 0 << '\n';
        else cout << (idx_L ? cum_sum[idx_R] - cum_sum[idx_L - 1] : cum_sum[idx_R]) << '\n';
    }

    return 0;
}