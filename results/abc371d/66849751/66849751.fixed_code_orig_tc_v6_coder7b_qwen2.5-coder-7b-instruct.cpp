#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Sort indices based on X values
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return X[a] < X[b]; });

    // Process each query efficiently using sorted indices
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(all(idx), L) - idx.begin();
        int r = upper_bound(all(idx), R) - idx.begin();
        cout << P[r] - P[l] << endl;
    }

    return 0;
}