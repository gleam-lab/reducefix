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
    vector<int> P(N + 1, 0); // Initialize P to zero
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i + 1]; // Read the increments from input

    map<int, int> x_to_ptr;
    rep(i, N) x_to_ptr.emplace(X[i], i);

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        // Correct handling of the bounds when they are outside the mapped range
        int l = (X_l == x_to_ptr.begin() ? 0 : (*X_l).second);
        int r = (X_r == x_to_ptr.end() ? N : (*X_r).second);

        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}