#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

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
        int L, R, l, r;
        cin >> L >> R;
        
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        if (X_l == x_to_ptr.end() || (*X_l).first > L) {
            // If L is greater than the last key or L is beyond the range
            l = 0;
        } else {
            l = (*X_l).second;
        }
        
        if (X_r == x_to_ptr.begin() || (*X_r).first < R) {
            // If R is less than the first key or R is beyond the range
            r = N;
        } else {
            r = (*X_r).second - 1; // Subtract 1 to get the last index of the range
        }
        
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}