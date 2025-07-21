#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1);
    P[0] = 0;
    rep(i, N) {
        ll X;
        cin >> X;
        P[i + 1] = P[i] + X;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        auto X_l = lower_bound(all(P), L);
        auto X_r = upper_bound(all(P), R);
        if (X_l == P.end()) {
            X_l = P.begin();
        }
        if (X_r == P.end()) {
            X_r = P.begin();
        }

        // Ensure l is less than or equal to r
        while (X_r != P.begin() && (X_r - 1)->second == (*X_r).second) {
            X_r--;
        }

        int l = (*X_l).second;
        int r = (*X_r).second;

        cout << (*X_r).first - (*X_l).first << endl;
    }
    return 0;
}