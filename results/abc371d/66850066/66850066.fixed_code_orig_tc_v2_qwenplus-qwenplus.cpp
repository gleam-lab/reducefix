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
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N), P(N+1, 0);
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Build prefix sum of values using sorted indices
    vector<pair<ll, int>> sorted_X;
    rep(i, N) sorted_X.emplace_back(X[i], i);
    sort(all(sorted_X));

    // Create mapping from X value to prefix index in sorted array
    vector<ll> prefix_sum(N+1, 0);
    rep(i, N) prefix_sum[i+1] = prefix_sum[i] + sorted_X[i].second;

    // For binary search operations
    vector<ll> sorted_values;
    rep(i, N) sorted_values.push_back(sorted_X[i].first);

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        // Binary search to find the first index with X >= L
        int left_idx = lower_bound(sorted_values.begin(), sorted_values.end(), L) - sorted_values.begin();
        // Binary search to find the first index with X > R
        int right_idx = upper_bound(sorted_values.begin(), sorted_values.end(), R) - sorted_values.begin();

        // Sum of indices between left_idx and right_idx-1 in original array
        ll ans = P[right_idx] - P[left_idx];
        cout << ans << endl;
    }
}