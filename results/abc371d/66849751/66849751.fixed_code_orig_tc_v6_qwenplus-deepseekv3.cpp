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
    int N;
    cin >> N;
    vector<pair<int, ll>> Xp(N); // Store (X_i, p_i) pairs
    rep(i, N) cin >> Xp[i].first;
    rep(i, N) cin >> Xp[i].second;

    // Sort the array based on X_i values
    sort(all(Xp));

    // Create prefix sums array
    vector<ll> prefix(N + 1, 0);
    rep(i, N) prefix[i + 1] = prefix[i] + Xp[i].second;

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Find first element >= L
        auto it_l = lower_bound(all(Xp), make_pair(L, 0LL));
        int l = it_l - Xp.begin();

        // Find first element > R
        auto it_r = upper_bound(all(Xp), make_pair(R, LLONG_MAX));
        int r = it_r - Xp.begin();

        // Calculate the sum
        ll ans = prefix[r] - prefix[l];
        cout << ans << endl;
    }
}