#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0);
    vector<ll> X(N);

    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Map from position to index in X array
    map<ll, int> x_to_idx;
    rep(i, N) {
        x_to_idx[X[i]] = i;
    }

    // Build a sorted list of X positions for binary search
    vector<ll> sorted_X(X);
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Find first X >= L using lower_bound
        auto l_it = lower_bound(all(sorted_X), L);
        int left_idx = (l_it != sorted_X.end()) ? x_to_idx[*l_it] : N;

        // Find first X > R using upper_bound
        auto r_it = upper_bound(all(sorted_X), R);
        int right_idx = (r_it != sorted_X.end()) ? x_to_idx[*r_it] : N;

        ll ans = P[right_idx] - P[left_idx];
        cout << ans << endl;
    }

    return 0;
}