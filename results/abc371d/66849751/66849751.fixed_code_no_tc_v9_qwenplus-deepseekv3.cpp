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
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<int> P(N+1, 0);
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> sorted_X;
    rep(i, N){
        sorted_X.emplace_back(X[i], i);
    }
    sort(all(sorted_X));
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find first X[i] >= L
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        int l = (it_l == sorted_X.end()) ? N : it_l->second;
        
        // Find first X[i] > R
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        int r = (it_r == sorted_X.end()) ? N : it_r->second;
        
        // We need to include elements from l to r-1
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}