#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(X.begin(), X.end(), L);
        int l = it_l - X.begin();
        
        auto it_r = upper_bound(X.begin(), X.end(), R);
        int r = it_r - X.begin() - 1;
        
        ll ans = 0;
        if (l <= r && r < N && l >= 0) {
            ans = P[r + 1] - P[l];
        }
        cout << ans << '\n';
    }

    return 0;
}