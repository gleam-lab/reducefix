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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Coordinate compression for X values
    vector<ll> sorted_X = X;
    sort(all(sorted_X));
    map<ll, int> x_to_idx;
    rep(i, N) x_to_idx[sorted_X[i]] = i;

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Find left bound index using lower_bound
        int l = distance(X.begin(), lower_bound(all(X), L));
        // Find right bound index using upper_bound
        int r = distance(X.begin(), upper_bound(all(X), R));

        // Query prefix sum
        cout << P[r] - P[l] << "\n";
    }

    return 0;
}