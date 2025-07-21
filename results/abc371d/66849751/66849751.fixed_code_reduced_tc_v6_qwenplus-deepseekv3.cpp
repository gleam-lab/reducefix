#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> p(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> p[i];
    vector<int> prefix(N + 1, 0);
    rep(i, N) prefix[i + 1] = prefix[i] + p[i];

    vector<pair<int, int>> indexed_X;
    rep(i, N) indexed_X.emplace_back(X[i], i);
    sort(all(indexed_X));

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto it_l = lower_bound(all(indexed_X), make_pair(L, 0));
        auto it_r = upper_bound(all(indexed_X), make_pair(R, N));
        int l = it_l - indexed_X.begin();
        int r = it_r - indexed_X.begin();
        int ans = prefix[r] - prefix[l];
        cout << ans << endl;
    }
}