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
    vector<ll> X(N), P(N+1, 0);
    rep(i, N) cin >> X[i];
    rep(i, N){
        cin >> P[i+1];
        P[i+1] += P[i];
    }
    
    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        auto l_it = lower_bound(all(X), L);
        auto r_it = upper_bound(all(X), R);
        int l = l_it - X.begin();
        int r = r_it - X.begin() - 1;
        if (l > r) {
            cout << 0 << endl;
        } else {
            cout << P[r+1] - P[l] << endl;
        }
    }
}