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
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> x_index(N);
    rep(i, N){
        x_index[i] = {X[i], i};
    }
    sort(all(x_index));
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto cmp = [](const pair<int, int>& a, int b) { return a.first < b; };
        auto lower = lower_bound(all(x_index), L, cmp);
        auto upper = upper_bound(all(x_index), R, cmp);
        
        int l = (lower == x_index.end()) ? N : lower->second;
        int r = (upper == x_index.end()) ? N : upper->second;
        
        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}