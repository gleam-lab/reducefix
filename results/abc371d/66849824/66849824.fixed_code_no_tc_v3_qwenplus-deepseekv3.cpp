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
    vector<ll> X(N), p(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> p[i];
    
    // Create a vector of pairs (X_i, p_i) and sort by X_i
    vector<pair<ll, ll>> xp(N);
    rep(i, N) xp[i] = {X[i], p[i]};
    sort(all(xp));
    
    // Create prefix sums of p_i sorted by X_i
    vector<ll> prefix(N+1, 0);
    rep(i, N) prefix[i+1] = prefix[i] + xp[i].second;
    
    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto it_l = lower_bound(all(xp), make_pair(L, 0LL));
        // Find first X_i > R
        auto it_r = upper_bound(all(xp), make_pair(R, LLONG_MAX));
        
        int l = it_l - xp.begin();
        int r = it_r - xp.begin();
        
        cout << prefix[r] - prefix[l] << endl;
    }
}