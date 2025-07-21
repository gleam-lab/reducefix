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
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a vector of pairs (X[i], i) and sort it by X[i]
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
        
        // Find the first X >= L using lower_bound
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        int l = (it_l == sorted_X.end()) ? N : it_l->second;
        
        // Find the first X > R using upper_bound
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        int r = (it_r == sorted_X.end()) ? N : it_r->second;
        
        // Make sure l is the minimum index and r is the maximum index
        // in the range [L, R]
        if (it_l != sorted_X.begin()) {
            // Find the smallest index in the range
            int min_idx = l;
            for (auto it = it_l; it != sorted_X.end() && it->first <= R; ++it) {
                if (it->second < min_idx) min_idx = it->second;
            }
            l = min_idx;
        }
        
        if (it_r != sorted_X.begin()) {
            // Find the largest index in the range
            int max_idx = (it_r == sorted_X.end()) ? -1 : it_r->second;
            for (auto it = it_l; it != it_r; ++it) {
                if (it->second > max_idx) max_idx = it->second;
            }
            r = max_idx + 1;  // +1 because P is 1-indexed
        }
        
        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}