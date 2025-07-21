#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1);
    P[0] = 0;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    ll p;
    rep(i, N) {
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    map<int, int> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        // Adjust pointers if they are at the end of the map
        if (X_r == x_to_ptr.end()) {
            X_r--;
        }

        int l = X_l->second;
        int r = X_r->second;

        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}