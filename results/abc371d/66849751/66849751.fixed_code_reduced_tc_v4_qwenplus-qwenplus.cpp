#include <bits/stdc++.h>

using namespace std;
using ll = long long;
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
    
    // Create a vector of pairs to store X[i] and its corresponding prefix sum index
    vector<pair<int, ll>> sorted_X(N);
    rep(i, N) {
        sorted_X[i] = {X[i], P[i+1]};
    }
    // Sort the vector based on X values
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Use lower_bound and upper_bound on the sorted vector
        auto left = lower_bound(all(sorted_X), make_pair(L, 0LL));
        auto right = upper_bound(all(sorted_X), make_pair(R, 0LL));
        
        ll ans = 0;
        if (left != sorted_X.end()) {
            ll sum_left = (*left).second;
            ll sum_right = (right != sorted_X.begin()) ? (*(right-1)).second : 0;
            ans = sum_right - sum_left;
        } else {
            ans = 0;
        }
        
        cout << ans << endl;
    }
}