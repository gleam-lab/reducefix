#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    map<ll, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        int l = (X_l == x_to_ptr.end()) ? N : (*X_l).second;
        int r = (X_r == x_to_ptr.begin() || prev(X_r)->first >= R) ? N : prev(X_r)->second;

        // If r is still N, it means no valid index was found to the right of R,
        // so we use the last index (N-1) instead since P[N] is not a valid prefix sum index.
        if (r == N) {
            r = N - 1;
        }

        ll ans = P[r + 1] - P[l];
        cout << ans << endl;
    }
}