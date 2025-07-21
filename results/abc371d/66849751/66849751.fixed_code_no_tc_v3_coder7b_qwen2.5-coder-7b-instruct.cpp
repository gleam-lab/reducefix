#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define reps(i, n) for(int i = 0; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        auto lb = lower_bound(all(X), L);
        auto ub = upper_bound(all(X), R);
        int l = distance(X.begin(), lb);
        int r = distance(X.begin(), ub);
        if(l == N || X[l] > R) --l; // Adjust if the left boundary is out of range or exceeds R
        if(r == N || X[r] < L) ++r; // Adjust if the right boundary is out of range or less than L
        cout << P[r] - P[l] << '\n';
    }

    return 0;
}