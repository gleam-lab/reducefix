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
    vector<int> P(N + 1);
    vector<ll> X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    
    // Create a vector of pairs (X[i], prefix_sum[i+1])
    // and sort by X[i]
    vector<pair<ll, int>> x_prefix(N);
    rep(i, N) {
        x_prefix[i] = {X[i], P[i + 1]};
    }
    sort(all(x_prefix));
    
    // Build prefix sums of the sorted values for efficient range queries
    vector<ll> prefix_sums(N + 1, 0);
    rep(i, N) {
        prefix_sums[i + 1] = prefix_sums[i] + x_prefix[i].second;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        
        // Binary search to find the range in the sorted array
        int left = lower_bound(all(x_prefix), make_pair(L, 0)) - x_prefix.begin();
        int right = upper_bound(all(x_prefix), make_pair(R, INT_MAX)) - x_prefix.begin();
        
        ll ans = prefix_sums[right] - prefix_sums[left];
        cout << ans << endl;
    }
}