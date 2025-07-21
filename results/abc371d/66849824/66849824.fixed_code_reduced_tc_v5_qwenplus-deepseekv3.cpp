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
    vector<ll> X(N);
    vector<ll> P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<ll, int>> sorted_X;
    rep(i, N){
        sorted_X.emplace_back(X[i], i);
    }
    sort(all(sorted_X));
    
    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        
        // Find first X_i >= L
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        int l = (it_l == sorted_X.end()) ? N : it_l->second;
        
        // Find first X_i > R
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        int r = (it_r == sorted_X.end()) ? N : it_r->second;
        
        // The range we want is [l, r-1]
        // But we need to find the min and max indices in this range
        // because X is not sorted by index
        if (l >= r) {
            cout << 0 << endl;
            continue;
        }
        
        int min_idx = N;
        int max_idx = 0;
        for (auto it = it_l; it != it_r; ++it) {
            min_idx = min(min_idx, it->second);
            max_idx = max(max_idx, it->second);
        }
        
        // The sum is from min_idx to max_idx inclusive
        // So we need P[max_idx+1] - P[min_idx]
        ll ans = P[max_idx+1] - P[min_idx];
        cout << ans << endl;
    }
}