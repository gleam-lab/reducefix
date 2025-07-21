#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << '\n'
#define YES(b) cout << ((b) ? "YES" : "NO") << '\n'

const int INF = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        if (X_l == x_to_ptr.end()) {
            Yes(0);
        } else if (X_r == x_to_ptr.end()) {
            Yes(0);
        } else {
            int l = (*X_l).second + 1;
            int r = (*X_r).second + 1;
            if (l <= R && L <= r) {
                cout << P[r] - P[l] << '\n';
            } else {
                Yes(0);
            }
        }
    }

    return 0;
}