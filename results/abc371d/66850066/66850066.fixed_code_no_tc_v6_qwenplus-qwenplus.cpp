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
    vector<ll> P(N + 1), X(N);
    
    rep(i, N) cin >> X[i];
    P[0] = 0;
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i) instead of using map
    vector<pair<int, int>> x_with_index(N);
    rep(i, N) {
        x_with_index[i] = {X[i], i};
    }
    sort(all(x_with_index));

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search to find the leftmost index where X[i] >= L
        int l = lower_bound(all(x_with_index), make_pair(L, -1)) - x_with_index.begin();
        
        // Binary search to find the rightmost index where X[i] <= R
        // We use upper_bound and subtract 1 because upper_bound returns the first element > target
        int r = upper_bound(all(x_with_index), make_pair(R, N)) - x_with_index.begin();

        // The total number of people in the range [L, R]
        int ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}