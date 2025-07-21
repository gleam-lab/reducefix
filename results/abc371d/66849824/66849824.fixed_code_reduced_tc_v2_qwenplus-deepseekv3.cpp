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
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    map<int, int> x_to_ptr;
    rep(i, N){
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        int l, r;
        if (X_l == x_to_ptr.begin() && X_l == x_to_ptr.end()){
            // All X[i] are outside the range
            l = N;
            r = 0;
        } else if (X_l == x_to_ptr.end()){
            // All X[i] are < L
            l = N;
            r = N;
        } else {
            l = (*X_l).second;
            if (X_r == x_to_ptr.begin()){
                // All X[i] are > R
                r = 0;
            } else if (X_r == x_to_ptr.end()){
                // All X[i] are <= R
                r = N;
            } else {
                r = (*X_r).second;
            }
        }
        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}