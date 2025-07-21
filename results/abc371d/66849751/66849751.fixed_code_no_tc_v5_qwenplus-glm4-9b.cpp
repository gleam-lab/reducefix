#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define repb(i,b,n) for (int i=b; i<(n); ++i)
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
    vector<int> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    repb(i, 0, N) cin >> P[i + 1] - P[i];
    
    map<int, int> x_to_ptr;
    repb(i, 0, N) x_to_ptr.emplace(X[i], i);
    
    int Q;
    cin >> Q;
    rep(i, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        // Adjust indices for the one-based problem statement
        if (X_l == x_to_ptr.begin() && L == (*X_l).first){
            int l = (*X_l).second;
            if (l == 0) l++;  // Adjust for the 0-based index
            int r = (*next(X_l, X_r))->second;
            cout << P[r] - P[l] << endl;
        } else {
            int l = X_l == x_to_ptr.end() ? 0 : (*X_l).second;
            int r = X_r == x_to_ptr.end() ? N : (*X_r).second;
            if (l == 0) l++;  // Adjust for the 0-based index
            cout << P[r] - P[l] << endl;
        }
    }
}