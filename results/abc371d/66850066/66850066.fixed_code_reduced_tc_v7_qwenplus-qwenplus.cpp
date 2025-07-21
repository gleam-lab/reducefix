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
    
    // Read coordinates
    rep(i, N) cin >> X[i];
    
    // Read values and build prefix sum
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Build coordinate mapping to sorted indices
    vector<pair<int, int>> x_idx(N);
    rep(i, N) x_idx[i] = {X[i], i};
    sort(all(x_idx));
    
    // Extract sorted coordinates for binary search
    vector<int> sorted_x(N);
    rep(i, N) sorted_x[i] = x_idx[i].first;
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find left bound (first element >= L)
        int l_pos = lower_bound(all(sorted_x), L) - sorted_x.begin();
        
        // Find right bound (first element > R)
        int r_pos = upper_bound(all(sorted_x), R) - sorted_x.begin();
        
        // Query prefix sum
        ll ans = P[r_pos] - P[l_pos];
        cout << ans << endl;
    }
}