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
    vector<ll> P(N + 1);
    vector<int> X(N);
    
    rep(i, N) cin >> X[i];
    P[0] = 0;
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Create a sorted list of x positions with their indices
    vector<pair<int, int>> x_with_index(N);
    rep(i, N) {
        x_with_index[i] = {X[i], i};
    }
    sort(all(x_with_index));

    // Extract sorted x positions and corresponding indices
    vector<int> sorted_x(N), index_map(N);
    rep(i, N) {
        sorted_x[i] = x_with_index[i].first;
        index_map[i] = x_with_index[i].second;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search to find the range
        int l = lower_bound(all(sorted_x), L) - sorted_x.begin();
        int r = upper_bound(all(sorted_x), R) - sorted_x.begin();

        // Get prefix sum in the range [l, r)
        int ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}