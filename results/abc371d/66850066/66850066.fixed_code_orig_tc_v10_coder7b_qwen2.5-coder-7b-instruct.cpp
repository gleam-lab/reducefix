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
    map<int, int> x_to_ptr;
    rep(i, N){
        x_to_ptr.emplace(X[i], i);
    }
    // for (const auto& [k, v] : x_to_ptr){
    //     cout << "X_i is " << k << " and i is " << v << endl;
    // }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        if (X_l == x_to_ptr.end()) {
            X_l = prev(x_to_ptr.end());
        }
        if (X_r == x_to_ptr.begin()) {
            X_r = x_to_ptr.begin();
        } else {
            --X_r;
        }
        int l = X_l->second;
        int r = X_r->second;
        // cout << "X_l is " << (*X_l).first << " and X_r is " << (*X_r).first << endl;
        // cout << "l is " << l << " and r is " << r << endl;
        int ans = P[r+1] - P[l];
        cout << ans << endl;
    }
}