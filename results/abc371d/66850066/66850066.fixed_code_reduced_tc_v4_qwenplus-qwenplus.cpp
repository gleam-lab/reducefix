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
    int N;
    cin >> N;
    vector<ll> P(N+1), X(N);
    
    rep(i, N) cin >> X[i];
    P[0] = 0;
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a sorted vector of pairs instead of map to use binary search
    vector<pair<int, int>> x_with_idx(N);
    rep(i, N){
        x_with_idx[i] = {X[i], i};
    }
    sort(all(x_with_idx));
    
    // Prepare for binary search
    vector<int> sorted_x(N);
    rep(i, N) sorted_x[i] = x_with_idx[i].first;
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find left bound using lower_bound
        int l_idx = lower_bound(sorted_x.begin(), sorted_x.end(), L) - sorted_x.begin();
        
        // Find right bound using upper_bound
        int r_idx = upper_bound(sorted_x.begin(), sorted_x.end(), R) - sorted_x.begin();
        
        // Get prefix sum indices
        int start = l_idx;
        int end = r_idx;
        
        ll ans = P[end] - P[start];
        cout << ans << endl;
    }
}