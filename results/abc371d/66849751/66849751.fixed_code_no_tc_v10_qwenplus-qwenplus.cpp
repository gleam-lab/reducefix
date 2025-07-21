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
    vector<int> P(N+1), X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Map from position to index in X array
    map<int, int> x_to_index;
    rep(i, N) {
        x_to_index[X[i]] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Find first X >= L
        auto l_it = x_to_index.lower_bound(L);
        int l_idx = (l_it != x_to_index.end()) ? l_it->second : N;

        // Find first X > R
        auto r_it = x_to_index.upper_bound(R);
        int r_idx = (r_it != x_to_index.end()) ? r_it->second : N;

        int ans = P[r_idx] - P[l_idx];
        cout << ans << endl;
    }

    return 0;
}