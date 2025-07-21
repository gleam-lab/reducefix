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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Prepare sorted list of (X[i], prefix sum up to i)
    vector<pair<ll, ll>> sortedX_PrefixSum(N);
    rep(i, N) {
        sortedX_PrefixSum[i] = {X[i], P[i+1]};
    }
    sort(all(sortedX_PrefixSum));

    // Build prefix sums for the sorted values
    vector<ll> prefix_sums(N + 1, 0);
    rep(i, N) {
        prefix_sums[i + 1] = prefix_sums[i] + sortedX_PrefixSum[i].second;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Binary search to find the range of X values within [L, R]
        auto left = lower_bound(sortedX_PrefixSum.begin(), sortedX_PrefixSum.end(), make_pair(L, 0LL));
        auto right = upper_bound(sortedX_PrefixSum.begin(), sortedX_PrefixSum.end(), make_pair(R, numeric_limits<ll>::max()));

        int l_idx = left - sortedX_PrefixSum.begin();
        int r_idx = right - sortedX_PrefixSum.begin();

        ll ans = prefix_sums[r_idx] - prefix_sums[l_idx];
        cout << ans << "\n";
    }

    return 0;
}