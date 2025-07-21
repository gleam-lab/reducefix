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
    map<ll, int> x_to_ptr;
    rep(i, N){
        x_to_ptr[X[i]] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        auto it_l = x_to_ptr.lower_bound(L);
        auto it_r = x_to_ptr.upper_bound(R);
        int l = (it_l == x_to_ptr.end()) ? N : it_l->second;
        int r = (it_r == x_to_ptr.end()) ? N : it_r->second;
        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}