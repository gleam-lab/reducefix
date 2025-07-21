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

    // Add sentinel value at end to simplify upper_bound logic
    X.push_back(INT_MAX);

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Find leftmost index with position >= L
        int l_idx = distance(X.begin(), lower_bound(X.begin(), X.end(), L));
        
        // Find rightmost index with position <= R
        // upper_bound returns first element > R, so subtract 1
        int r_idx = distance(X.begin(), upper_bound(X.begin(), X.end(), R)) - 1;

        // If no elements <= R, r_idx will be -1 which we cap to 0
        if (r_idx < 0) r_idx = 0;

        // Compute the prefix sum difference
        int ans = P[r_idx+1] - P[l_idx];
        cout << ans << endl;
    }
}