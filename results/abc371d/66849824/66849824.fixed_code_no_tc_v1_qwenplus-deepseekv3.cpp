#include <bits/stdc++.h>

using namespace std;
using ll=long long;
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
    int N;
    cin >> N;
    vector<ll> X(N), P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a vector of pairs (X[i], i) and sort it
    vector<pair<int, int>> xi;
    rep(i, N) xi.emplace_back(X[i], i);
    sort(all(xi));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find first element >= L
        auto it_l = lower_bound(all(xi), make_pair(L, 0));
        int l = (it_l == xi.end()) ? N : it_l->second;
        
        // Find first element > R
        auto it_r = upper_bound(all(xi), make_pair(R, N));
        int r = (it_r == xi.end()) ? N : it_r->second;
        
        // Since the array is sorted, all elements between l and r-1 satisfy L <= X[i] <= R
        // But we need to get the correct indices
        // The minimal l is the smallest index where X[i] >= L
        // The r is the first index where X[i] > R
        // So the range is [l, r)
        
        // However, the indices in xi are original indices, not necessarily consecutive
        // So P[r] - P[l] doesn't make sense directly
        
        // Instead, we need to sum P for all elements in [l, r) in the sorted order
        // So we need to track cumulative sums of the sorted elements
        
        // Alternatively, we can create a prefix sum array of the sorted P values
        vector<ll> sorted_P(N+1, 0);
        rep(i, N) sorted_P[i+1] = sorted_P[i] + P[xi[i].second+1] - P[xi[i].second];
        
        ll ans = 0;
        if (it_l != xi.end()) {
            int pos_l = it_l - xi.begin();
            int pos_r = it_r - xi.begin();
            ans = sorted_P[pos_r] - sorted_P[pos_l];
        }
        cout << ans << endl;
    }
}