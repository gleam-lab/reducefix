#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int N;
    cin >> N;
    vector<ll> P(N+1, 0); // Initialize all elements to 0
    vector<int> X(N);
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
        if (X_l == x_to_ptr.end() || (*X_l).first != L){
            cout << 0 << endl; // If L is not in the range or out of bounds
        } else if (X_r == x_to_ptr.begin() || (*X_r).first != R + 1){
            cout << 0 << endl; // If R is not in the range or out of bounds
        } else {
            cout << P[(*X_r).second] - P[(*X_l).second] << endl;
        }
    }
}