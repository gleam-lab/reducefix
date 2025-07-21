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
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];
    
    vector<pair<ll, ll>> sorted_X;
    rep(i, N){
        sorted_X.emplace_back(X[i], P[i]);
    }
    sort(all(sorted_X));
    
    vector<ll> prefix_sum(N+1, 0);
    rep(i, N){
        prefix_sum[i+1] = prefix_sum[i] + sorted_X[i].second;
    }
    
    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0LL));
        auto it_r = upper_bound(all(sorted_X), make_pair(R, LLONG_MAX));
        int l = it_l - sorted_X.begin();
        int r = it_r - sorted_X.begin();
        ll ans = prefix_sum[r] - prefix_sum[l];
        cout << ans << endl;
    }
}