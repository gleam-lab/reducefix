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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    P[0] = 0;
    rep(i, N) cin >> X[i];

    vector<ll> prefix_sums(N + 1);
    prefix_sums[0] = 0;
    rep(i, N) prefix_sums[i + 1] = prefix_sums[i] + X[i];

    map<ll, int> x_to_ptr;
    rep(i, N) x_to_ptr[X[i]] = i;

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(all(prefix_sums), L) - begin(prefix_sums);
        int r = upper_bound(all(prefix_sums), R) - begin(prefix_sums) - 1;

        ll ans = prefix_sums[r + 1] - prefix_sums[l];
        cout << ans << endl;
    }

    return 0;
}