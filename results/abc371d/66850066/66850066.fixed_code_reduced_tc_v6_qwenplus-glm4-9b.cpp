#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << '\n'
#define YES(b) cout << ((b) ? "YES" : "NO") << '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0), X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i + 1];
    P[0] = 0;

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

        // Adjust the pointers to handle edge cases
        if (X_l == x_to_ptr.begin()) {
            X_l++;
        }
        if (X_r == x_to_ptr.end()) {
            X_r--;
        }

        // Calculate the sums using the pointers
        ll l_sum = L > X[0] ? P[x_to_ptr[L]] : P[0];
        ll r_sum = R < X[N - 1] ? P[x_to_ptr[R]] : P[N];
        ll ans = r_sum - l_sum;

        cout << ans << '\n';
    }
}