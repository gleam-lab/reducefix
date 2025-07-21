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
        
        auto lower = lower_bound(all(sorted_X), make_pair(L, 0));
        auto upper = upper_bound(all(sorted_X), make_pair(R, N));
        
        int l = (lower == sorted_X.end()) ? N : lower->second;
        int r = (upper == sorted_X.end()) ? N : upper->second;
        
        if (l > r) {
            cout << 0 << endl;
            continue;
        }
        
        // The actual range is from min(l,r) to max(l,r)
        // But we need the sum from the first to last element in [L,R]
        // So we need to find the first and last indices in the sorted array
        int first_idx = (lower == sorted_X.end()) ? N : lower - sorted_X.begin();
        int last_idx = (upper == sorted_X.end()) ? N : upper - sorted_X.begin() - 1;
        
        if (first_idx > last_idx) {
            cout << 0 << endl;
            continue;
        }
        
        int actual_l = sorted_X[first_idx].second;
        int actual_r = sorted_X[last_idx].second;
        
        if (actual_l > actual_r) {
            // Need to find the minimal and maximal indices in the range
            actual_l = N;
            actual_r = -1;
            for (int i = first_idx; i <= last_idx; ++i) {
                actual_l = min(actual_l, sorted_X[i].second);
                actual_r = max(actual_r, sorted_X[i].second);
            }
        }
        
        if (actual_l > actual_r) {
            cout << 0 << endl;
        } else {
            cout << P[actual_r + 1] - P[actual_l] << endl;
        }
    }
}