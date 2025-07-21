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
    vector<int> P(N+1);
    vector<ll> X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a sorted vector of pairs (X[i], prefix sum up to i+1)
    vector<pair<ll, int>> sorted_X_Prefix(N);
    rep(i, N) {
        sorted_X_Prefix[i] = {X[i], P[i+1]};
    }
    sort(all(sorted_X_Prefix));

    // Build prefix sums for the sorted values
    vector<ll> prefix_sum(N+1, 0);
    rep(i, N) {
        prefix_sum[i+1] = prefix_sum[i] + sorted_X_Prefix[i].second;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        
        // Find the left and right indices using binary search
        auto left = lower_bound(all(sorted_X_Prefix), make_pair(L, -1LL << 60));
        auto right = upper_bound(all(sorted_X_Prefix), make_pair(R, 1LL << 60));
        
        int l_idx = left - sorted_X_Prefix.begin();
        int r_idx = right - sorted_X_Prefix.begin();
        
        ll ans = prefix_sum[r_idx] - prefix_sum[l_idx];
        cout << ans << endl;
    }
}