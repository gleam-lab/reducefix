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
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_ptr.upper_bound(R); // Corrected to x_ptr (typo in the original code)
        if (X_l == x_to_ptr.end() || X_l->first > R) {
            l = N; // If the lower bound goes out of range or is greater than R
        } else {
            l = X_l->second;
        }
        if (X_r == x_to_ptr.end()) {
            r = N;
        } else {
            r = X_r->second + 1; // Include the end point in the range
        }

        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}